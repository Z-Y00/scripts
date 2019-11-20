https://bbs.pythontab.com/thread-2551-1-1.html

```
import numpy as np
from math import pow
from operator import add,mul
from functools import reduce



data = [4.5,6.5,7,8,10,12]

print('数据：')
print(data)


#数据个数
size = len(data)


#数据求和
total = sum(data)


#数据平均值
mean = total/size


#数据中值
def compute_median(data):
    #计算中值
    size = len(data)
    pos = int(size/2)
    if size % 2 == 0:
        median = (data[pos]+data[pos-1])/2
    else:
        median = data[pos]
    return median
median = compute_median(data)


#几何平均值
def compute_geometric_mean(data):
    #计算几何平均值
    size = len(data)
    return pow(reduce(mul,data),1.0/size)

geometric_mean = compute_geometric_mean(data)

#调和平均值
def compute_harmonic_mean(data):
    #计算调和平均值
    size = len(data)
    return size/sum([1.0/i for i in data])
harmonic_mean = compute_harmonic_mean(data)


print()
print('中心位置测定值')
print('算术平均值：%s'%mean)
print('中值：%s'%median)
print('几何平均值：%.2f'%geometric_mean)
print('调和平均值：%.2f'%harmonic_mean)



#最小值
min_value = min(data)

#最大值
max_value = max(data)

#全距
range_value = max_value - min_value

#样本平方差
def compute_s2(data,mean):
    #计算样本平方差

    return 1.0/(len(data)-1)*reduce(add,map(lambda x:(x-mean)**2,data))
s2 = compute_s2(data,8.0)

#样本标准偏差
standard_deviation = pow(s2,1.0/2)

#变异系数
CV =standard_deviation/mean

#百分位数

pos1 = int(size * 1/4)
Q1 = data[pos1]
pos2 = int(size * 2/4)
Q2 = data[pos2]
pos3 = int(size * 3/4)
Q3 = data[pos3]


print()
print('分散度测定值')
print('最小值：%s'%min_value)
print('最大值：%s'%max_value)
print('全距：%s'%range_value)
print('标准偏差：%.2f'%standard_deviation)
print('变异系数：%.2f'%CV)
print('第一四分位数：%s'%Q1)
print('第二四分位数：%s'%Q2)
print('第三四分位数：%s'%Q3)

```
