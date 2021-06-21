legend(bbox_to_anchor=(0,0))
https://stackoverflow.com/a/40909660/8428146

legend.labelspacing , better control the legend
https://matplotlib.org/stable/tutorials/introductory/customizing.html?highlight=legend.labelspacing#a-sample-matplotlibrc-file
```
params = {
          'legend.labelspacing':  0.2 ,
          'legend.handlelength':  0.5,
          'legend.fancybox': false,
          
```

log scale on y
https://matplotlib.org/3.1.1/api/_as_gen/matplotlib.pyplot.yscale.html

if your tick is too long, use \n to break the xticks

names = ["C\nA","C","E","F","G","L","P","E\nX","G\nR","T","R"]

subplot adjust
wspace = 0.2
plt.subplots_adjust(right = 2 )
plt.subplots_adjust(wspace = 0.5 )
https://matplotlib.org/3.1.1/api/_as_gen/matplotlib.pyplot.subplots_adjust.html

config bar width
https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.bar.html

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
```
from matplotlib.ticker import FormatStrFormatter
from matplotlib import ticker
for app in apps:
  eum = 0
  nth = nth + 1
  plt.subplot(1,len(apps),nth)
  for dataset in datasets:
    eum = eum + 1
    speedup_S = []
    #build the ratio
    # print (app)
    counter = 1
    s = []
    s_= []
    # for dataset in datasets:
    for bandwidth in skip_segs:

    #   print(dataset)
    #   print(datas[app][dataset])
    #   print(datas[app][dataset]["32"]["cache_lens"])
      up = datas[app][dataset]["bandwidth"][bandwidth]/datas[app][dataset]["bandwidth"]["1"]
      up = 1/up
      s.append(up)
    #   print(up)
      speedup_allS.append(up)
    #   s_.append(counter)
      s_.append(bandwidth)
      counter=counter+1
    #   print(s_)
    #   print(s)
    ind = np.arange(len(s))
    # if (eum == 1):
      # plt.ylabel("Normalized performance", fontweight = "bold")
    plt.xticks(ind, bandw)
    plt.gca().yaxis.set_major_formatter(ticker.StrMethodFormatter("{x:.1f}"))
    # else:
      # plt.yticks([])  
    if (nth == 1):
      plt.ylabel("Speedup over 64-bits/cycle", fontsize = 10, fontweight = "bold")
    if (nth == 2):
      plt.xlabel("Number of elements / cycle", fontweight = "bold")      
    print(names[eum-1])
    print(dataset)
    plt.plot(s_, s,label = names[eum-1] )
    #   plt.title(app_names_dic[app], fontsize = fs, fontweight = "bold")
    # plt.tight_layout()

  plt.subplots_adjust(right = 4.4 )
  # plt.title(app_names_dic[app], fontsize = fs, fontweight = "bold")
  title_obj = plt.title(app_names_dic[app], fontsize = fs, fontweight = "bold")
  # if nth in [5,6,7,8,9]: 
  #  plt.setp(title_obj, color='r')   
# plt.title('sensitive study -- cache length')
leg=plt.legend(bbox_to_anchor=(0.5,-0.1), ncol=5)
# for text in leg.get_texts():
    # plt.setp(text, color = 'r')
# plt.legend()
# plt.subplots_adjust(right = 1.5 )
plt.savefig("./sensitive_bandwidth.pdf", bbox_inches='tight')
```
