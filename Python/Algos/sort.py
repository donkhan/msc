# -*- coding: utf-8 -*-
"""
Created on Tue Sep 17 14:36:31 2019

@author: 1msc11
"""

def bubble_sort(a):
    print("Bubble Sort...")
    print("UnSorted Order..." + str(a))
    for i in range(len(a)-1,0,-1):
        for j in range(i+1,len(a)):
            if(a[i] > a[j]):
                t = a[i]
                a[i] = a[j]
                a[j] = t
        print("Pass " + str(len(a)-i) + " " + str(a))
    print("Sorted Order..." + str(a))
    
def selection_sort(a):
    print("Selection Sort....")
    print("UnSorted Order..." + str(a))
    for i in range(0,len(a)):
        pos = i
        val = a[pos]
        for j in range(i+1,len(a)):
            if(a[j] < val):
                val = a[j]
                pos = j
        t = a[i]
        a[i] = a[pos]
        a[pos] = t
        print("Pass " + str(i+1) + " " + str(a))
    print("Sorted Order..." + str(a))
    
def main():    
    a = [1,4,5,2,3,7]
    bubble_sort(a)
    print("-------------------------------------------------------------------")
    a = [1,4,5,2,3,7]
    selection_sort(a)

main()


