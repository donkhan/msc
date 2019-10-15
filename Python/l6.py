# -*- coding: utf-8 -*-
"""
Created on Tue Oct 15 14:44:08 2019

@author: 1msc11
"""

months = ("January","Feburary","March","April","May","June","July","August",
          "September","October","November","December")

print("Names of Months...")
print(months)    

print("Names of Ist 6 months")
for i in range(0,6):
    print(months[i],end=',')
    
print()
    
l = list(months)
l[0] = "JJanuary"
t = tuple(l)
print(t)
    