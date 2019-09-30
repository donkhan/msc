# -*- coding: utf-8 -*-
"""
Created on Tue Aug 20 14:34:29 2019

@author: 1msc11
"""

s= input()

numbers = 0
alphas = 0
for i in s:
    if i >= '0' and i <= '9':
            numbers = numbers + 1
    if i >= 'a' and i <= 'z':
            alphas = alphas + 1
    if i >= 'A' and i <= 'Z':
            alphas = alphas + 1

print(numbers)
print(alphas)