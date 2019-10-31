# -*- coding: utf-8 -*-
"""
Created on Fri Sep 20 09:52:03 2019

@author: 1msc11
"""

a = [[1,2],[3,4]]
b = [[5,6],[7,8]]
c = [[0,0],[0,0]]

for i in range(0,len(a)):
    for j in range(0,len(a[0])):
        for k in range(0,len(a[0])):
            c[i][j] = c[i][j] + a[i][k] * b[k][j] 

print("----------------")


for i in range(0,len(a)):
    for j in range(0,len(a[0])):
        print( str(c[i][j]), end=" ")
    print("")


