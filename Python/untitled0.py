# -*- coding: utf-8 -*-
"""
Created on Fri Sep 20 09:30:31 2019

@author: 1msc11
"""

a = [[0,0],[0,0]]
b = [[0,0],[0,0]]
c = [[0,0],[0,0]]

i = 0
j = 0

while i < len(a):
    while j < len(a[0]):
        a[i][j] = int(input())
        b[i][j] = int(input())
        print(a[i][j] + " "+ b[i][j])