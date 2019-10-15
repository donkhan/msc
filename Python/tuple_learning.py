# -*- coding: utf-8 -*-
"""
Created on Tue Oct 15 12:22:46 2019

@author: 1msc11
"""

fruits = ("apple","banana","orange")
l = list(fruits)

print(" Length of Tuple " ,len(fruits))

tup3 = (1,2,3,4,5,6)

print(tup3[1:])
print(tup3[2:4])

print(".".join(fruits))

t = (1,2,3,4,1,2,3)

print(t.count(3))

for fruit in fruits:
    print(fruit)
    
f1,f2,f3 = fruits

print(f2)

print(max(tup3))