# -*- coding: utf-8 -*-
"""
Created on Mon Aug 26 14:32:36 2019

@author: 1msc11
"""


def send_chars(c,count):
    s = ''
    for i in range(0,count,1):
        s = s + c
    return s

def space(count):
    return send_chars(' ',count)

def f(row):
    if row == 1 or row == 3:
        return send_chars("F",7)
    if row == 2 or row == 4 or row == 5:
        return send_chars("F",2) + space(5)
    
def u(row):
    if row == 1 or row == 2 or row == 3:
        return send_chars("U",1) + space(5) + send_chars("U",1)
    if row == 4:
        return space(1) + send_chars("U",1) + space(3) + send_chars("U",1) + space(1)
    if row == 5:
        return space(2) + send_chars("U",3) + space(2)

def n(row):
    if row == 1:
        return send_chars("N",2) + space(4) + send_chars("N",2)
    if row == 2:
        return send_chars("N",3) + space(3) + send_chars("N",2)
    if row == 3:
        return send_chars("N",2) + space(1) + send_chars("N",1) + space(2) + send_chars("N",2)
    if row == 4:
        return send_chars("N",2) + space(2) + send_chars("N",1) + space(1) + send_chars("N",2)
    if row == 5:
        return send_chars("N",2) + space(3) + send_chars("N",3)
    return space(7)

def main():
    input_char = input("Enter the Chars [F,U,N] are only digitised...")
    for i in range(1,6,1):
        line = ''
        for c in input_char:
            if c == 'F':
                line = line + f(i)
            if c == 'U':
                line = line + u(i)    
            if c == 'N':
                line = line + n(i)
            line = line + space(1)
        print(line);
    
main()

