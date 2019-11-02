# -*- coding: utf-8 -*-
"""
Created on Tue Aug 20 14:18:22 2019

@author: 1msc11

    
"""
import math

def is_prime(n):
    for i in range(2,int(math.sqrt(n))+1):
        if n % i == 0:
            return True
    return False

def main():
    n = int(input("Please Enter The No..."))
    for i in range(2,n+1):
        if(is_prime(i) == False):
            print(i,end=",")
          
    
main()