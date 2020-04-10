def is_there(l,f):
    for e in l:
        if e[0] is f :
            return True
    return False


def find_lru(q):
    min_lru = q[0][0]
    min_lru_time =  q[0][1]
    min_lru_pos = 0
    for i in range(1,len(q)):
        if q[i][1] < min_lru_time:
            min_lru = q[i][0]
            min_lru_time = q[i][1]
            min_lru_pos = i
    return min_lru_pos

def find_pos(q,e):
    for i in range(0,len(q)):
        if e is q[i][0]:
            return i

def find(input,fs,debug):
    s = map(int,input.split(","))
    pf = 0
    q = [None] * fs
    for i in range(0, fs):
        q[i] = (s[i] , i)
        pf = pf + 1
    for i in range(fs, len(s)):
        if is_there(q,s[i]) is False:
            pf = pf + 1
            min_lru_pos = find_lru(q)
            q[min_lru_pos] = (s[i],i)
        else:
            pos = find_pos(q,s[i])
            q[pos] = (s[i],i)
    print "Final Page Faults ",pf
    print "*************************************************"


find("1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6",4,True)
find("1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6",3,True)

