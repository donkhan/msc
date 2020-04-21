def is_there(l,f):
    for e in l:
        if e is f :
            return True
    return False


def shift_add(e,l,fs):
    for i in range(0,fs-1):
        l[i] = l[i+1]
    l[fs-1] = e


def find(input,fs,debug):
    s = map(int,input.split(","))
    pf = 0
    q = [None] * fs
    for i in range(0, fs):
        q[i] = s[i]
        pf = pf + 1

    for i in range(fs, len(s)):
        if debug:
            print "-----------------"
            print "Accessing ", s[i]
            print q
        if is_there(q, s[i]) is False:
            shift_add(s[i], q, fs)
            pf = pf + 1
        if debug:
            print q
            print "PF ", pf
    print "Final Page Faults ",pf
    print "*************************************************"


#find("7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1",3,False)
#find("1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6",3,True)
#find("1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6",4,True)
#find("1,2,3,2,1,5,2,1,6,2,5,6,3,1,3,6,1,2,4,3",3,True)
find("1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5",3,True)
find("1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5",4,True)
