import matplotlib.pyplot as plt
import numpy as np

x = [100, 200, 500, 700, 1000, 2000, 5000, 7000, 10000, 20000, 50000, 70000, 100000, 200000, 500000]
y = [40, 84, 191, 253, 370, 659, 1621, 2255, 3237, 6367, 16927, 22454, 31929, 65071, 160149]

plt.xticks(np.arange(0, 600000, step = 100000))
plt.yticks(np.arange(0, 1500000, step = 100000))

plt.scatter(x, y, s=20, c='b')
plt.plot(x,y)

plt.xlabel('Array size')
plt.ylabel('Time, mcs')
plt.show()