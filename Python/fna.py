# -*- coding: utf-8 -*-
"""
Created on Wed Aug 21 11:20:54 2019

@author: 1msc11
"""

def rf(mark,max_mark):
    if mark > max_mark:
        return True

def wr(mark):
    if rf(mark,90) is True:
        print("A")
    elif rf(mark,80) is True:
        print("B")
    elif rf(mark,70) is True:
        print("C")
    elif rf(mark,60) is True:
        print("D")
    else:
        print("F")

def fo(mark,max_marks,grades,i):
    if i >= len(max_marks):
        print("Fail")
    elif mark > max_marks[i]:
        print("Mark", mark,grades[i])
    else:
        fo(mark,max_marks,grades,i+1)

def wo(mark):
    fo(mark,[90,80,70,60],['A','B','C','D'],0)
    

def x(n):
    pass

print(x(12))

