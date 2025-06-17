import math
import numpy as np
import matplotlib.pyplot as plt


def f(z):
    return 1 / (1 + math.e ** (-z))


x = np.linspace(-10, 10, 20)
plt.figure(num=3, figsize=(10, 5))
plt.plot(x,f(x),color='blue')

plt.xlim(-10,10)
plt.xlabel('z')
plt.ylabel('f(z)')

plt.show()