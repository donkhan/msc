# -*- coding: utf-8 -*-
"""
Created on Tue Oct  1 15:34:21 2019

@author: 1msc11
"""

def bs(l,ele):
    print("Searching in " + str(l))
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
    l = [1,2,3,4,5]
    print("List is " + str(l))
    found = bs(l,int(input("Enter the Value to Search: ")))
    if found is True:
        print("Found...")
    else:
        print("Not Found...")

main()