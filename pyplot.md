legend(bbox_to_anchor=(0,0))
https://stackoverflow.com/a/40909660/8428146

legend.labelspacing , better control the legend
https://matplotlib.org/stable/tutorials/introductory/customizing.html?highlight=legend.labelspacing#a-sample-matplotlibrc-file

log scale on y
https://matplotlib.org/3.1.1/api/_as_gen/matplotlib.pyplot.yscale.html

wished precision on the y axis
also https://matplotlib.org/stable/gallery/ticks_and_spines/tick-formatters.html
```
import matplotlib.pyplot as plt
import numpy as np
from matplotlib.ticker import FormatStrFormatter

fig, ax = plt.subplots()

ax.yaxis.set_major_formatter(FormatStrFormatter('%g'))
ax.yaxis.set_ticks(np.arange(-2, 2, 0.25))

x = np.arange(-1, 1, 0.1)
plt.plot(x, x**2)
plt.show()
```
