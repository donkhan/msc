from itertools import combinations
from math import pow

x = 2000
inp = [2,3,5,7]
length = len(inp)
op = list()

def get_mod(t):
    p = 1
    for i in range(0,len(t)):
        p = p * t[i]
    return p

for i in range(0,length):
    op.append(0)
    l = list(combinations(inp,i+1))
    for e in l:
        mod = get_mod(e)
        for j in range(1,x+1):
            if j % mod == 0:
                op[i] = op[i] + 1
for i in range(0,length):
    op[i] = int(pow(-1,i) * op[i])

print(op)
print(x-sum(op))
