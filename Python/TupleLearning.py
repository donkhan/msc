# -*- coding: utf-8 -*-
"""
Created on Fri Oct  4 09:20:10 2019

@author: 1msc11
"""

print(type((1,"S")))

week_days = ('Sunday','Monday')

for day in week_days:
    print(day)
    
(sun,sat) = week_days

print(sun)    


def x(l):
    return min(l),max(l)

(minimum,maximum) = x([1,2,3,2,5,4,7,1])
print(minimum)


print((1,2,))

l = [1,2]

a = "AAAA"

del a
del l

def a():
    return 1


t_fn = (a(),a())
print(t_fn)