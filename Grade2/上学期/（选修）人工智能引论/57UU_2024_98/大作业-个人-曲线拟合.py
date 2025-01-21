import torch
import numpy as np
from torch.utils.data import Dataset
from torch.utils.data import DataLoader
from torch import nn
from torch.nn import functional as F
from tqdm import tqdm

Batch_size=1

device = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")

def load_data(file_name:str)->torch.Tensor:
    data = np.load("data-set/"+file_name)
    return torch.tensor(data).float().permute(1,0).to(device)

class TrainDataSet(Dataset):
    def __init__(self):
        self.data = load_data("train_x.npy")
        self.label = load_data("train_y.npy")
    def __len__(self):
        return len(self.data)
    def __getitem__(self, index):
        return self.data[index], self.label[index]

class TestDataSet(Dataset):
    def __init__(self):
        self.data = load_data("test_x.npy")
        self.label = load_data("test_y.npy")
    def __len__(self):
        return len(self.data)
    def __getitem__(self, index):
        return self.data[index], self.label[index]
    
trainDataSet=TrainDataSet()
testDataSet=TestDataSet()

trainDataLoader=DataLoader(trainDataSet, batch_size=Batch_size, shuffle=True)
testDataLoader=DataLoader(testDataSet, batch_size=Batch_size, shuffle=True)

class Net(nn.Module):
    def __init__(self):
        super(Net, self).__init__()
        self.fc1 = torch.nn.Linear(1, 100)
        self.fc2 = torch.nn.Linear(100, 500)
        self.fc3 = torch.nn.Linear(500, 500)
        self.fc4=torch.nn.Linear(500,500)
        self.fc5=torch.nn.Linear(500,500)
        self.fc6=torch.nn.Linear(500*3,1)
    def forward(self, x):
        #batch x 32
        x=self.fc1(x)
        x=F.leaky_relu(x)
        x1=torch.zeros(x.shape[0],500).to(device)
        x1[:,:100]=x
        x=self.fc2(x)
        x2=x
        x=F.leaky_relu(x)
        x=self.fc3(x)
        x3=x
        x=F.leaky_relu(x)
        x=self.fc4(x)
        x=F.leaky_relu(x)
        x=self.fc5(x)
        x=F.leaky_relu(x)
        x=torch.cat((x,x2,x3),dim=1)
        x=self.fc6(x)
        return x

net=Net().to(device)

def train(net=net,epoch=20,loss_fn=F.mse_loss,optimizer=None):
    net.train()
    if optimizer is None:
        optimizer = torch.optim.Adam(net.parameters())
    for epoch in tqdm(range(1, epoch + 1),total=epoch,desc="train"):
        for batch_idx, (data, target) in enumerate(trainDataLoader):
            optimizer.zero_grad()
            output = net(data)
            loss = loss_fn(output, target)
            loss.backward()
            optimizer.step()
            if batch_idx % 10 == 0 and False:
                print('Train Epoch: {} [{}/{} ({:.0f}%)]\tLoss: {:.6f}'.format(
                    epoch, batch_idx * len(data), len(trainDataLoader.dataset),
                    100. * batch_idx / len(trainDataLoader), loss.item()))
            
def test(net=net,loss_fn=F.mse_loss):
    net.eval()
    test_loss = 0
    correct = 0
    with torch.no_grad():
        for data, target in testDataLoader:
            output = net(data)
            test_loss += loss_fn(output, target).item()
    test_loss /= len(testDataLoader.dataset)
    print('\nTest set: Average loss: {:.4f}\n'.format(
        test_loss))
    return test_loss
def draw_dataset_picture(dataset):
    x=torch.stack([dataset[i][0] for i in range(len(dataset))])
    y=torch.stack([dataset[i][1] for i in range(len(dataset))])
    draw_picture(x,y)

def draw_train():
    draw_dataset_picture(trainDataSet)

def draw_test():
    draw_dataset_picture(testDataSet)
def draw_picture(x: torch.Tensor, y: torch.Tensor):
    import matplotlib.pyplot as plt
    
    with torch.no_grad():
        y_hat = net(x).cpu().detach()
    x = x.cpu()
    y = y.cpu()
    plt.figure(figsize=(10, 5))
    plt.plot(x, y, label='y')
    plt.plot(x, y_hat,"k*", label='y_hat')
    plt.xlabel('x')
    plt.ylabel('y')
    plt.legend()
    plt.show()


print("current device",device)

train(epoch=2000)
draw_test()