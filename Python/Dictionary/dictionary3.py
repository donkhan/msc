# -*- coding: utf-8 -*-
"""
Created on Tue Oct 22 14:41:19 2019

@author: 1msc11
"""



d = {
    'L1' : [1,2,3],
    'L2' : [3,4]
}

print("Using Built in ")
for key in d.keys():
    print(key, sum(d[key]))

print("---------------------------")
print("Without Using Built in ")
for key in d.keys():
    l = d[key]
    s = 0
    for i in l:
        s = s + i
    print(key,s)