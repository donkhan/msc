# -*- coding: utf-8 -*-
"""
Created on Tue Oct 15 14:27:50 2019

@author: 1msc11
"""

def p(t,x):
    if len(t) > x:
        print(t[len(t)-x])
    else:
        print("length of tuple is ", len(t), ". So not possible")
t = ('k','a','m','i','l','k','h','a','n')

p(t,4)
p(t,5)

