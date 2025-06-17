import torch
import torch.nn as nn
import matplotlib.pyplot as plt
import numpy as np
import random

device = torch.device("cuda:0" if torch.cuda.is_available() else 'cpu')

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

# 生成测试数据
test_data = torch.randn(128, 100).to(device)  # 随机噪声

# 加载模型
model = Generator(100).to(device)
model.load_state_dict(torch.load('Generator_mnist.pth'))
model.eval()

# 生成图像
pred = np.squeeze(model(test_data).detach().cpu().numpy())

# 创建图形并设置大小
plt.figure(figsize=(10, 10))  # 在这里设置图形大小

# 绘制子图
for i in range(64):
    plt.subplot(8, 8, i + 1)
    plt.imshow((pred[i] + 1) / 2, cmap='gray')
    plt.axis('off')

# 调整子图间距
plt.subplots_adjust(wspace=0.1, hspace=0.1)

# 保存图像（不再需要figsize参数）
plt.savefig('image.png', bbox_inches='tight', dpi=300)
plt.close()  # 关闭图形，释放内存