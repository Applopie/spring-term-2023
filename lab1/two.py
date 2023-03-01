import matplotlib.pyplot as plt
import numpy as np

x = [100, 200, 500, 700, 1000, 2000, 5000, 10000, 20000, 70000, 100000, 200000, 300000, 400000, 500000]
y = [79, 88, 78, 152, 153, 159, 169, 201, 199, 244,  253, 258, 264, 299, 322]

plt.xticks(np.arange(0, 600000, step = 100000))
plt.yticks(np.arange(0, 1500000, step = 100000))

plt.scatter(x, y, s=20, c='b')
plt.plot(x,y)

plt.xlabel('Array size')
plt.ylabel('Time, microseconds')
plt.show()
