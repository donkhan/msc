# -*- coding: utf-8 -*-
"""
Created on Tue Sep 24 14:17:00 2019

@author: 1msc11
v = int(input("Enter the Value to search...."))
"""

l = [1,2,3,4,5,7,8,9,10]
v = int(input("Enter the Value to search...."))



low = 0
high = len(l)

mid = (low + high) // 2
pos = -1
p = 0

while low < high-1:
    value = l[mid]
    print("Mid " + str(mid) + " Comparing "+ str(v) + " with "+ str(value))
    if value == v:
        pos = mid
        break;
    if value < v:
        low = mid
    if value > v:
        high = mid
    mid = (low + high) // 2
    print("Low " + str(low) + " High " + str(high))
   


if pos != -1:
    print(str(v) + " found at "+ str(pos))
else:
    print(str(v) + " not found ")