# -*- coding: utf-8 -*-
"""
Created on Tue Oct  1 15:48:11 2019
sort([2,1,4,5,6,3,7,9,23,34,145])
print(sort([2,1,4,5]))
@author: 1msc11
"""


def merge(list_1,list_2):
    l1 = len(list_1)
    l2 = len(list_2)
    i = 0
    j = 0
    k = 0
    l = []
    while(i < l1 and j < l2):
        if list_1[i] <  list_2[j]:
            l.append(list_1[i])
            i = i + 1
        else:
            l.append(list_2[j])
            j = j + 1
        k = k + 1
    while(i < l1):
        l.append(list_1[i])
        i = i + 1
    while(j < l2):
        l.append(list_2[j])
        j = j + 1
    return l

def sort(l):
   if len(l) > 1:
       mid = len(l) // 2
       return merge(sort(l[0:mid]),sort(l[mid:len(l)]))
   return l
    

def main():
    print(sort([2,1,4,5,6,3,7,9,23,34,145]))

main()
    