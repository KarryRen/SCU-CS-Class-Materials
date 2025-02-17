import matplotlib.pyplot as plt
import numpy as np

# 定义时序图参数
start_signal_duration = 100  # 微秒
data_bit_duration = 100  # 微秒
end_signal_duration = 100  # 微秒

# 定义字节数据
byte_data = 0b00101100

# 计算总时间
total_time = start_signal_duration + 8 * data_bit_duration + end_signal_duration

# 创建时间轴
time_axis = np.arange(0, total_time, 10)  # 每10微秒一个点

# 创建信号数组
signal = np.zeros_like(time_axis)

# 添加开始信号
signal[0:start_signal_duration // 10] = 0
signal[start_signal_duration // 10:(2 * start_signal_duration) // 10] = 1

# 添加数据位
current_time = 2 * start_signal_duration
for i in range(8):
    bit = (byte_data >> i) & 1
    if bit:
        signal[current_time // 10:(current_time + data_bit_duration) // 10] = 1
    else:
        signal[current_time // 10:(current_time + data_bit_duration) // 10] = 0
    current_time += data_bit_duration

# 添加结束信号
signal[current_time // 10:(current_time + end_signal_duration) // 10] = 0
signal[(current_time + end_signal_duration) // 10:(current_time + 2 * end_signal_duration) // 10] = 1

# 绘制时序图
plt.figure(figsize=(12, 2))
plt.step(time_axis, signal, where='post', color='blue')
plt.yticks([0, 1], ['Low', 'High'])
plt.xticks(np.arange(0, total_time + 1, 100), [f'{i} μs' for i in range(0, total_time + 1, 100)])
plt.grid(True, which='both', linestyle='--', linewidth=0.5)
plt.title('GPIO Data Transmission Timing Diagram')
plt.xlabel('Time (μs)')
plt.ylabel('Signal Level')

# 添加注释
plt.text(start_signal_duration / 2, 0.5, 'Start', ha='center', va='center', fontsize=10, color='red')
plt.text((start_signal_duration + data_bit_duration * 8) / 2, 0.5, 'Data', ha='center', va='center', fontsize=10, color='red')
plt.text((start_signal_duration + data_bit_duration * 8 + end_signal_duration) / 2, 0.5, 'End', ha='center', va='center', fontsize=10, color='red')

# 显示图形
plt.show()