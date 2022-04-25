import numpy as np
import matplotlib.pyplot as plt
from math import log10

x = np.arange(0,20) #time
y1 = 2**x
y2 = x**4


plt.plot(x, y1)
plt.plot(x, y2)
plt.legend(["y1", "y2"])
plt.show()
