import itertools


l = itertools.combinations(sorted(['m','r','a','f','t']),3)

for c in l:
    print(c)