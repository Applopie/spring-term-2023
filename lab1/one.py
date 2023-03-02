import matplotlib.pyplot as plt
import numpy as np

x = [100, 200, 500, 700, 1000, 2000, 5000, 7000, 10000, 20000, 50000, 70000, 100000, 200000, 500000]
y = [34, 63, 177, 187, 402, 740, 1255, 1743, 3456, 6740, 11879, 16839, 27318, 55519, 129116]

plt.xticks(np.arange(0, 600000, step = 100000))
plt.yticks(np.arange(0, 1500000, step = 100000))

plt.scatter(x, y, s=20, c='b')
plt.plot(x,y)

plt.xlabel('Array size')
plt.ylabel('Time, mcs')
plt.show()