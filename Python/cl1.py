# -*- coding: utf-8 -*-
"""
Created on Tue Aug 27 12:46:12 2019

@author: 1msc11
"""

l = [0,0,0,0,0,0]
sum = 0

for i in range(0,len(l)):
    l[i] = int(input("Enter the new number ....."  ))
    sum = sum + l[i]

avg = sum / len(l)
no_above_average = 0

for i in range(0,len(l)):
    if l[i] > avg:
        no_above_average = no_above_average + 1
    
print("Average is " , avg)
print("Number of elements above average " , no_above_average)
    


