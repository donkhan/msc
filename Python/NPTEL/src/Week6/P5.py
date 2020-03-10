import random

def search(l,loc,item):
    if loc < 0:
        loc = 0
    if l[loc] == item:
        print("Found Item ",item, " at ",loc)
        return(loc)
    if loc == len(l) -1:
        print("Element Not Present ")
        return(0)
    else:
        return(search(l,loc+1,item))

l = [1,2,3,4,5,6,7,8,9]
print(search(l,-11,3))

print(search(l,-11,23))

print(search(l,8,3))
