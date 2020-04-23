def solve(s):
    from itertools import combinations
    length = len(s)
    l = []
    for i in range(1,length+1):
        sl = list(combinations(s,i))
        for e in sl:
            l.append(''.join(e))
    l = sorted(l)
    return l

print(solve('abc'))