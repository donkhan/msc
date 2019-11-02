# -*- coding: utf-8 -*-
"""
Created on Thu Oct 31 14:47:13 2019

@author: 1msc11
"""

fd = open("c:\\Users\\1msc11\\aaa.txt","r")
words = 0
for line in fd:
    words = words + len(line.split())

print("No of Words in the file ",words)
