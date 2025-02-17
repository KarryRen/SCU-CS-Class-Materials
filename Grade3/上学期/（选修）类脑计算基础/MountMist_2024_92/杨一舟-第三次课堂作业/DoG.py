import cv2
import numpy as np
import matplotlib.pyplot as plt

def dog_filter(image, sigma1, sigma2):
    # 创建高斯滤波器
    g1 = cv2.GaussianBlur(image, (0, 0), sigma1)
    g2 = cv2.GaussianBlur(image, (0, 0), sigma2)
    # 计算DoG
    dog = g1 - g2
    return dog

# 加载图像
image = cv2.imread('./TEXAS.jpg', 0)  # 读取为灰度图像

# 设置DoG的两个标准差
sigma1 = 1.0
sigma2 = 2.0

# 应用DoG滤波器
dog_result = dog_filter(image, sigma1, sigma2)

# 显示结果
plt.subplot(1, 2, 1)
plt.imshow(image, cmap='gray')
plt.title('Original Image')
plt.subplot(1, 2, 2)
plt.imshow(dog_result, cmap='gray')
plt.title('DoG Result')
plt.show()
