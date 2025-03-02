import RPi.GPIO as GPIO
import time

# GPIO设置
GPIO.setmode(GPIO.BCM)  # 使用BCM编号方式
GPIO.setup(18, GPIO.OUT)  # 设置GPIO18为输出模式

def send_byte(byte):
    # 发送开始信号
    GPIO.output(18, GPIO.LOW)
    time.sleep(0.0001)  # 100微秒
    GPIO.output(18, GPIO.HIGH)
    time.sleep(0.0001)  # 100微秒
    
    # 发送8位数据
    for i in range(8):
        bit = (byte >> i) & 1  # 取出最低位
        if bit:
            GPIO.output(18, GPIO.HIGH)
        else:
            GPIO.output(18, GPIO.LOW)
        time.sleep(0.0001)  # 每个数据位持续100微秒
    
    # 发送结束信号
    GPIO.output(18, GPIO.LOW)
    time.sleep(0.0001)  # 100微秒
    GPIO.output(18, GPIO.HIGH)
    time.sleep(0.0001)  # 100微秒

try:
    # 发送字节00101100
    send_byte(0b00101100)
finally:
    GPIO.cleanup()  # 清理GPIO设置