import cv2
import numpy as np
import matplotlib.pyplot as plt

def dog_filter(image, sigma1, sigma2):
    # 创建高斯滤波器
    kernel1 = cv2.getGaussianKernel(ksize=5, sigma=sigma1)
    kernel2 = cv2.getGaussianKernel(ksize=5, sigma=sigma2)
    
    kernel1 = kernel1 * kernel1.T
    kernel2 = kernel2 * kernel2.T
    
    # 对图像应用高斯滤波器
    blurred1 = cv2.filter2D(image, -1, kernel1)
    blurred2 = cv2.filter2D(image, -1, kernel2)
    
    # 计算DoG
    dog = blurred1 - blurred2
    return dog

# 读取图像
image = cv2.imread('TEXAS.jpg', cv2.IMREAD_GRAYSCALE)

# 调整DoG参数并观察效果
sigma1_values = [1, 2, 3]
sigma2_values = [2, 3, 5]

fig, axes = plt.subplots(len(sigma1_values), len(sigma2_values), figsize=(12, 8))
for i, sigma1 in enumerate(sigma1_values):
    for j, sigma2 in enumerate(sigma2_values):
        result = dog_filter(image, sigma1, sigma2)
        axes[i, j].imshow(result, cmap='gray')
        axes[i, j].set_title(f'Sigma1={sigma1}, Sigma2={sigma2}')
        axes[i, j].axis('off')

plt.tight_layout()
plt.show()
