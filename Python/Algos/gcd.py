# -*- coding: utf-8 -*-
"""
Created on Fri Aug 23 09:26:15 2019

@author: 1msc11
"""

def gcd(tup):
    print(tup)
    for i in range(tup[0],0,-1):
        if tup[1] % i == 0 and tup[0] % i == 0:
            print("GCD is ", i)
            return

def min_pair(a,b):
    if a > b:
        t = a
        a = b
        b = t
    return (a,b)

a=int(input("Enter A  "))
b=int(input("Enter B  "))

gcd(min_pair(a,b))

  