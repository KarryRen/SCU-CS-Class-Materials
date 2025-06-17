import torch
import torch.nn as nn
import torch.optim as optim
from torchvision import datasets, transforms
from torch.utils.data import DataLoader
import matplotlib.pyplot as plt


# 自定义BatchNorm2d模块（参考文档段落）
class CustomBatchNorm2d(nn.Module):
    def __init__(self, num_features, momentum=0.9, eps=1e-5):
        super(CustomBatchNorm2d, self).__init__()
        self.num_features = num_features
        self.momentum = momentum
        self.eps = eps

        self.gamma = nn.Parameter(torch.ones((1, num_features, 1, 1)))
        self.beta = nn.Parameter(torch.zeros((1, num_features, 1, 1)))

        self.register_buffer('moving_mean', torch.zeros((1, num_features, 1, 1)))
        self.register_buffer('moving_var', torch.ones((1, num_features, 1, 1)))

    def forward(self, x):
        if self.training:
            # 计算当前batch的均值和方差，并分离出计算图
            batch_mean = x.mean(dim=(0, 2, 3), keepdim=True).detach()
            batch_var = x.var(dim=(0, 2, 3), keepdim=True, unbiased=False).detach()

            # 使用no_grad更新移动平均和方差
            with torch.no_grad():
                self.moving_mean.copy_(self.momentum * self.moving_mean + (1 - self.momentum) * batch_mean)
                self.moving_var.copy_(self.momentum * self.moving_var + (1 - self.momentum) * batch_var)

            x_normalized = (x - batch_mean) / torch.sqrt(batch_var + self.eps)
            return self.gamma * x_normalized + self.beta
        else:
            x_normalized = (x - self.moving_mean) / torch.sqrt(self.moving_var + self.eps)
            return self.gamma * x_normalized + self.beta


class CustomBatchNorm1d(nn.Module):
    def __init__(self, num_features, momentum=0.9, eps=1e-5):
        super(CustomBatchNorm1d, self).__init__()
        self.num_features = num_features
        self.momentum = momentum
        self.eps = eps

        self.gamma = nn.Parameter(torch.ones(num_features))
        self.beta = nn.Parameter(torch.zeros(num_features))

        self.register_buffer('moving_mean', torch.zeros(num_features))
        self.register_buffer('moving_var', torch.ones(num_features))

    def forward(self, x):
        if self.training:
            batch_mean = x.mean(dim=0).detach()
            batch_var = x.var(dim=0, unbiased=False).detach()

            with torch.no_grad():
                self.moving_mean.copy_(self.momentum * self.moving_mean + (1 - self.momentum) * batch_mean)
                self.moving_var.copy_(self.momentum * self.moving_var + (1 - self.momentum) * batch_var)

            x_normalized = (x - batch_mean) / torch.sqrt(batch_var + self.eps)
            return self.gamma * x_normalized + self.beta
        else:
            x_normalized = (x - self.moving_mean) / torch.sqrt(self.moving_var + self.eps)
            return self.gamma * x_normalized + self.beta

# 无Batch Normalization的模型
class LeNetWithoutBN(nn.Module):
    def __init__(self):
        super(LeNetWithoutBN, self).__init__()
        self.conv_layers = nn.Sequential(
            nn.Conv2d(3, 6, kernel_size=5),
            nn.ReLU(),
            nn.MaxPool2d(kernel_size=2, stride=2),
            nn.Conv2d(6, 16, kernel_size=5),
            nn.ReLU(),
            nn.MaxPool2d(kernel_size=2, stride=2)
        )
        self.fc_layers = nn.Sequential(
            nn.Linear(16 * 5 * 5, 120),
            nn.ReLU(),
            nn.Linear(120, 84),
            nn.ReLU(),
            nn.Linear(84, 10)
        )

    def forward(self, x):
        x = self.conv_layers(x)
        x = x.view(x.size(0), -1)
        x = self.fc_layers(x)
        return x


# 有Batch Normalization的模型
class LeNetWithBN(nn.Module):
    def __init__(self):
        super(LeNetWithBN, self).__init__()
        self.conv_layers = nn.Sequential(
            nn.Conv2d(3, 6, kernel_size=5),
            CustomBatchNorm2d(6),  # 添加BN层
            nn.ReLU(),
            nn.MaxPool2d(kernel_size=2, stride=2),
            nn.Conv2d(6, 16, kernel_size=5),
            CustomBatchNorm2d(16),  # 添加BN层
            nn.ReLU(),
            nn.MaxPool2d(kernel_size=2, stride=2)
        )
        self.fc_layers = nn.Sequential(
            nn.Linear(16 * 5 * 5, 120),
            CustomBatchNorm1d(120),  # 使用自定义的BatchNorm1d
            nn.ReLU(),
            nn.Linear(120, 84),
            nn.ReLU(),
            nn.Linear(84, 10)
        )

    def forward(self, x):
        x = self.conv_layers(x)
        x = x.view(x.size(0), -1)
        x = self.fc_layers(x)
        return x


# 数据预处理
transform = transforms.Compose([
    transforms.ToTensor(),
    transforms.Normalize((0.5, 0.5, 0.5), (0.5, 0.5, 0.5))  # 标准化输入
])

# 加载CIFAR-10数据集
train_dataset = datasets.CIFAR10(root='./data', train=True, download=True, transform=transform)
val_dataset = datasets.CIFAR10(root='./data', train=False, download=True, transform=transform)
train_loader = DataLoader(train_dataset, batch_size=128, shuffle=True)
val_loader = DataLoader(val_dataset, batch_size=128, shuffle=False)

# 模型、优化器、损失函数
model_no_bn = LeNetWithoutBN().cuda()
model_with_bn = LeNetWithBN().cuda()
optimizer_no_bn = optim.SGD(model_no_bn.parameters(), lr=0.01, momentum=0.9)
optimizer_with_bn = optim.SGD(model_with_bn.parameters(), lr=0.01, momentum=0.9)
criterion = nn.CrossEntropyLoss()

# 训练参数
epochs = 20
losses_no_bn = {'train': [], 'val': []}
losses_with_bn = {'train': [], 'val': []}


def train(model, optimizer, criterion, train_loader, val_loader, epochs, with_bn=False):
    model.train()
    for epoch in range(epochs):
        total_loss = 0.0
        for inputs, labels in train_loader:
            inputs, labels = inputs.cuda(), labels.cuda()
            optimizer.zero_grad()
            outputs = model(inputs)
            loss = criterion(outputs, labels)
            print(f"Epoch {epoch + 1}, Loss calculated: {loss.item()}")  # 添加调试信息
            loss.backward()
            optimizer.step()
            total_loss += loss.item() * inputs.size(0)

        # 验证阶段
        model.eval()
        val_loss = 0.0
        with torch.no_grad():
            for inputs, labels in val_loader:
                inputs, labels = inputs.cuda(), labels.cuda()
                outputs = model(inputs)
                loss = criterion(outputs, labels)
                val_loss += loss.item() * inputs.size(0)

        # 记录损失
        if with_bn:
            losses_with_bn['train'].append(total_loss / len(train_dataset))
            losses_with_bn['val'].append(val_loss / len(val_dataset))
        else:
            losses_no_bn['train'].append(total_loss / len(train_dataset))
            losses_no_bn['val'].append(val_loss / len(val_dataset))

        print(f"Epoch {epoch + 1}/{epochs}, Train Loss: {total_loss / len(train_dataset):.4f}, Val Loss: {val_loss / len(val_dataset):.4f}")


# 训练无BN和有BN的模型
train(model_no_bn, optimizer_no_bn, criterion, train_loader, val_loader, epochs, with_bn=False)
train(model_with_bn, optimizer_with_bn, criterion, train_loader, val_loader, epochs, with_bn=True)


def test_accuracy(model, data_loader):
    model.eval()
    correct = 0
    total = 0
    with torch.no_grad():
        for inputs, labels in data_loader:
            inputs, labels = inputs.cuda(), labels.cuda()
            outputs = model(inputs)
            _, predicted = torch.max(outputs.data, 1)
            total += labels.size(0)
            correct += (predicted == labels).sum().item()
    return 100 * correct / total


acc_no_bn = test_accuracy(model_no_bn, val_loader)
acc_with_bn = test_accuracy(model_with_bn, val_loader)
print(f"Test Accuracy (No BN): {acc_no_bn:.2f}%")
print(f"Test Accuracy (With BN): {acc_with_bn:.2f}%")

plt.figure(figsize=(10, 6))
plt.plot(losses_no_bn['train'], label='Train (No BN)')
plt.plot(losses_no_bn['val'], label='Val (No BN)', linestyle='--')
plt.plot(losses_with_bn['train'], label='Train (With BN)')
plt.plot(losses_with_bn['val'], label='Val (With BN)', linestyle='--')
plt.xlabel('Epoch')
plt.ylabel('Loss')
plt.title('Training and Validation Loss Comparison')
plt.legend()
plt.show()