# -*- coding: utf-8 -*-
"""
Created on Fri Sep 20 09:30:31 2019

@author: 1msc11
"""

a = [[1,2],[3,4]]
b = [[5,6],[7,8]]
c = [[0,0],[0,0]]

i = 0
while i < len(a):
    j = 0
    while j < len(a[0]):
        a[i][j] = int(input("a[" + str(i) + "][" + str(j) + "] = "))
        b[i][j] = int(input("b[" + str(i) + "][" + str(j) + "] = "))
        c[i][j] = a[i][j] +  b[i][j]
        j = j + 1
    i = i + 1


print("----------------")

i = 0
while i < len(a):
    j = 0
    while j < len(a[0]):
        print( str(c[i][j]), end=" ")
        j = j + 1
    print("")
    i = i + 1

