def check(l):
    for e in l:
        if e < 0:
            return False
    return True

def h_h(l,debug=False):
    l = sorted(l,reverse=True)
    if debug is True:
        print("---------------------")
        print(l)
    x = l[0]
    l = l[1:len(l)]
    for r in range(0,x):
        l[r] = l[r] - 1
    if check(l) is False:
        print("Not Graphic")
        return False
    if debug is True:
        print(l)
    if len(l) > 0:
        return h_h(l,debug)
    print("Graphic")
    return True


h_h([2,2,2,1,1])
h_h([4,2,2,2,2])
h_h([7,1,1,1,1,1,1,1])
h_h([5,2,1,1,1,1])
h_h([5,5,5,4,2,1,1,1],True)


