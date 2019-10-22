# -*- coding: utf-8 -*-
"""
Created on Tue Oct 22 14:20:07 2019

@author: 1msc11
"""

inventory = {
        'gold': 500,
        'pouch': [ 'flint','twine','gemstone'],
        'backpack' :  ['xylophone','dagger','bedroll','bread loaf']
}

inventory['pocket'] =  ['seashell','strange berry', 'lint']

print('After Adding', inventory)
sl = inventory['backpack']
print ('Before sorting ', sl )
sl.sort()

print ('After Sorting  ',sl )

print('Before removal ', inventory['backpack'])
inventory['backpack'].remove('dagger')

print('After removal ', inventory['backpack'])

print('Initial ',inventory['gold'])
inventory['gold'] = inventory['gold'] + 50

print('After ',inventory['gold'])


    


    

