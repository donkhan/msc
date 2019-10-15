# -*- coding: utf-8 -*-
"""
Created on Tue Oct 15 14:34:26 2019

@author: 1msc11
"""

def using_builtin():
    t = (1,2,3,4)   
    l = list(t)
    l.reverse()
    t = tuple(l)
    print(t)

def without_using_builtin():
    t = (1,2,3,4)   
    l = list(t)
    l1 = list()
    for e in l:
        l1.insert(len(l1),e)
    print(l1)


using_builtin()
without_using_builtin()
    
    