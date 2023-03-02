import matplotlib.pyplot as plt
import numpy as np

x = [100, 150, 200, 300, 400, 500, 750, 1000, 3000, 5000]
y = [1331, 2791, 5136, 11302, 33146, 28485, 63701, 128367, 1023543, 2785166]

plt.xticks(np.arange(0, 600000, step = 1000000))
plt.yticks(np.arange(0, 200, step = 25))

plt.scatter(x, y, s=20, c='b')
plt.plot(x,y)

plt.xlabel('Array size')
plt.ylabel('Time, microseconds')
plt.show()