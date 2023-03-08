import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

srA = pd.read_csv("strategy_C.csv")

x = srA['N'].tolist()

y = srA['A'].tolist()

z = srA['B'].tolist()

plt.xticks(np.arange(0, 1000000, step = 100000))
plt.yticks(np.arange(0, 3000000, step = 1000000))

plt.scatter(x, y, s = 20, c = 'b')
plt.scatter(x, z, s = 20, c = 'r')

plt.xlabel('Array size')
plt.ylabel('Time, mcs')
plt.show()