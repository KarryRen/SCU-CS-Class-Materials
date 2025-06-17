import torch
import torch.nn as nn
import torch.optim as optim
from torchvision import datasets, transforms
from torch.utils.data import DataLoader
import numpy as np
import matplotlib.pyplot as plt
 
 
class Generator(nn.Module):  # 生成器
    def __init__(self, latent_dim):
        super(Generator, self).__init__()
        self.model = nn.Sequential(
            nn.Linear(latent_dim, 256),
            nn.LeakyReLU(0.2),
            nn.Linear(256, 512),
            nn.LeakyReLU(0.2),
            nn.Linear(512, 1024),
            nn.LeakyReLU(0.2),
            nn.Linear(1024, 784),
            nn.Tanh()
        )
 
    def forward(self, z):
        img = self.model(z)
        img = img.view(img.size(0), 1, 28, 28)
        return img
 
 
class Discriminator(nn.Module):  # 判别器
    def __init__(self):
        super(Discriminator, self).__init__()
        self.model = nn.Sequential(
            nn.Linear(784, 512),
            nn.LeakyReLU(0.2),
            nn.Linear(512, 256),
            nn.LeakyReLU(0.2),
            nn.Linear(256, 1),
            nn.Sigmoid()
        )
 
    def forward(self, img):
        img = img.view(img.size(0), -1)
        validity = self.model(img)
        return validity
 
 
def gen_img_plot(model, test_input):
    pred = np.squeeze(model(test_input).detach().cpu().numpy())
    fig = plt.figure(figsize=(4, 4))
    for i in range(16):
        plt.subplot(4, 4, i + 1)
        plt.imshow((pred[i] + 1) / 2)
        plt.axis('off')
    plt.show(block=False)
    plt.savefig('gan_mnist.png', dpi=300, bbox_inches='tight')
 
 
# 调用GPU
device = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")
 
# 超参数设置
lr = 0.0001
batch_size = 128
latent_dim = 100
epochs = 50
 
# 数据集载入和数据变换
transform = transforms.Compose([
    transforms.ToTensor(),
    transforms.Normalize((0.5,), (0.5,))
])
 
# 训练数据
train_dataset = datasets.MNIST(root='./data', train=True, transform=transform, download=True)
train_loader = DataLoader(train_dataset, batch_size=batch_size, shuffle=True)
 
# 测试数据 torch.randn()函数的作用是生成一组均值为0，方差为1(即标准正态分布)的随机数
# test_data = torch.randn(batch_size, latent_dim).to(device)
test_data = torch.FloatTensor(batch_size, latent_dim).to(device)
 
# 实例化生成器和判别器，并定义损失函数和优化器
generator = Generator(latent_dim).to(device)
discriminator = Discriminator().to(device)
adversarial_loss = nn.BCELoss()
optimizer_G = optim.Adam(generator.parameters(), lr=lr)
optimizer_D = optim.Adam(discriminator.parameters(), lr=lr)
 
# 开始训练模型
for epoch in range(epochs):
    for i, (imgs, _) in enumerate(train_loader):
        batch_size = imgs.shape[0]
        real_imgs = imgs.to(device)
 
        # 训练判别器
        z = torch.FloatTensor(batch_size, latent_dim).to(device)
        z.data.normal_(0, 1)
        fake_imgs = generator(z)  # 生成器生成假的图片
 
        real_labels = torch.full((batch_size, 1), 1.0).to(device)
        fake_labels = torch.full((batch_size, 1), 0.0).to(device)
 
        real_loss = adversarial_loss(discriminator(real_imgs), real_labels)
        fake_loss = adversarial_loss(discriminator(fake_imgs.detach()), fake_labels)
        d_loss = (real_loss + fake_loss) / 2
 
        optimizer_D.zero_grad()
        d_loss.backward()
        optimizer_D.step()
 
        # 训练生成器
        z.data.normal_(0, 1)
        fake_imgs = generator(z)
 
        g_loss = adversarial_loss(discriminator(fake_imgs), real_labels)
        optimizer_G.zero_grad()
        g_loss.backward()
        optimizer_G.step()
 
        torch.save(generator.state_dict(), "Generator_mnist.pth")
 
    print(f"Epoch [{epoch}/{epochs}] Loss_D: {d_loss.item():.4f} Loss_G: {g_loss.item():.4f}")
 
# gen_img_plot(Generator, test_data)
gen_img_plot(generator, test_data)