# -*- coding: utf-8 -*-
"""
Created on Thu Oct 31 14:49:17 2019

@author: 1msc11
"""

# -*- coding: utf-8 -*-
"""
Created on Thu Oct 31 14:47:13 2019

@author: 1msc11
"""


n = int(input("Enter the no of lines..."))
fd = open("c:\\Users\\1msc11\\aaa.txt","r")
i = 0
for line in fd:
    print(line,end="")
    i = i + 1
    if i == n:
        break