# -*- coding: utf-8 -*-
"""
Created on Tue Oct  1 15:34:21 2019

@author: 1msc11
"""

def bs(l,ele):
    mid = len(l) // 2
    if l[mid] == ele:
        return True
    if len(l) == 1:
        return False
    if l[mid] > ele:
        return bs(l[0:mid],ele)
    else:
        return bs(l[mid:len(l)],ele)
    
    
def main():
    print(bs([1,2,3,4,5],15))
    print(bs([1,2,3,4,5],5))
    print(bs([1,2,3,4,5],1))
    print(bs([1,2,3,4,5],2))
    print(bs([1,2,3,4,5],-22))

main()