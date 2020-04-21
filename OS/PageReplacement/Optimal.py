def is_there(l,f):
    for e in l:
        if e is f :
            return True
    return False

def find_pos(e,pos,s):
    for i in range(pos,len(s)):
        if e == s[i]:
            return i
    return 20000


def find_max_pos(pos_array):
    max = pos_array[0]
    max_pos = 0
    for i in range(1, len(pos_array)):
        if max < pos_array[i]:
            max = pos_array[i]
            max_pos = i
    return max_pos


def find_which_one_to_replace(s,pos,q):
    pos_array = [None] * len(q)
    for i in range(0,len(q)):
        pos_array[i] = find_pos(q[i],pos+1,s)
    return q[find_max_pos(pos_array)]


def replace(q,e,ne):
    for i in range(0,len(q)):
        if q[i] == e:
            q[i] = ne
            break
    return q


def find(input,fs,debug):
    s = map(int,input.split(","))
    pf = 0
    q = [None] * fs
    for i in range(0, fs):
        q[i] = s[i]
        pf = pf + 1
    pos = fs

    for i in range(fs, len(s)):
        if is_there(q, s[i]) is False:
            e = find_which_one_to_replace(s,pos,q)
            q = replace(q,e,s[i])
            print q
            pf = pf + 1
        pos = pos + 1
    print "Final Page Faults ",pf
    print "*************************************************"

#find("7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1",3,False)
#find("1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6",3,True)
find("1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6",4,True)
