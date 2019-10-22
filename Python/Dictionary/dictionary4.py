# -*- coding: utf-8 -*-
"""
Created on Tue Oct 22 14:32:18 2019

@author: 1msc11
"""

def add_state(d):
    state = input('Enter the State to add : ')
    code = input('Enter Code of ' + state + ' : ')
    d[state] = code
    
def remove_state(d):
    state = input('Enter the State to delete : ')
    d.pop(state)

def iterate_keys_and_values(d):
    keys = d.keys()
    for i in keys:
        print(i)
    for i in d:
        print(d[i])

states_in_INDIA = dict()

states_in_INDIA['TamilNadu'] = 'TN'
states_in_INDIA['Kerala'] = 'KL'
states_in_INDIA['Karnataka'] = 'KR'
states_in_INDIA['Telangana'] = 'TL'

print("Length " , len(states_in_INDIA))
print("Presence of Kerala " , 'Kerala' in states_in_INDIA )

print('Before Add ' ,states_in_INDIA)    
add_state(states_in_INDIA)
print('After Add ' ,states_in_INDIA)    


print('Before Del ' ,states_in_INDIA)    
remove_state(states_in_INDIA)
print('After Del ' ,states_in_INDIA)    


iterate_keys_and_values(states_in_INDIA)