#!-*- coding:utf-8 -*-
import pandas as pd
import numpy as np
import matplotlib.pylab as plt
import re
from builtins import map
from datashape.coretypes import Map
Movie=pd.read_csv('./douban_top250.csv') #数据读取
Movie.head()
#Rating pie
Rating=Movie['评分']
bins=[8,8.5,9,9.5,10]  #分区(0,8],(8,8.5]....
rat_cut=pd.cut(Rating,bins=bins)
rat_class=rat_cut.value_counts()  #统计区间个数
rat_pct=rat_class/rat_class.sum()*100  #计算百分比
rat_arr_pct=np.array(rat_pct)#将series格式转成array，为了避免pie中出现name
f1=plt.figure(figsize=(9,9))
plt.title('DoubanMovieTop250\nRatingDistributin(0~10)')
plt.pie(rat_arr_pct,labels=rat_pct.index,colors=['r','g','b','c'],autopct='%.2f%%',startangle=75,explode=[0.05]*4)  #autopct属性显示百分比的值
plt.savefig('MovieTop250.RatingDistributin(0~10).png')
f1.show()

# year pie
year = Movie['年份']
for i in year.index:
    if len(year[i]) > 4:
        year.drop(i, inplace=True)  # year.drop(i,inplace=True)  去除多个年代的特例,inplace重要，修改改变原值
year = year.astype(int)
bins = np.linspace(min(year) - 1, max(year) + 1, 10).astype(int)  # 产生区间,bins一般为(,]的，所以+1
year_cut = pd.cut(year, bins=bins)
year_class = year_cut.value_counts()
year_pct = year_class / year_class.sum() * 100
year_arr_pct = np.array(year_pct)
color = ['b', 'g', 'r', 'c', 'm', 'y', (0.2, 0.5, 0.7), (0.6, 0.5, 0.7), (0.2, 0.7, 0.1)]  # RGB 0-1之间的tuple
f2 = plt.figure(figsize=(9, 9))
patches, out_text, in_text = plt.pie(year_arr_pct, labels=year_pct.index, colors=color, autopct='%.2f%%',
                                     explode=[0.05] * 9, startangle=30)
plt.title('MovieTop250\nYears Distribution')
f2.show()
# plt.savefig('MovieTop250_YearsDistribution.png')



