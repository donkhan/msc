def solve_i(n):
    if n == 1:
        return [1]
    if n == 2:
        return [1,2,1]
    s = solve_i(n-1)
    #print(s)
    l = list()
    l.append(1)
    for i in range(0,len(s)-1):
        l.append(s[i] + s[i+1])
    l.append(1)
    return l

def solve(n):
    s = solve_i(n)
    l = []
    for i in range(0,len(s)):
        l.append(s[i] % pow(10,9))
    return l


'''
s = solve(971)
c = 0
for i in s:
    c = c+1
    if c% 9 == 0:
        print()
    print(i, end=" ")
fd = open("/tmp/t10.txt")

for line in fd:
    if line == '\n':
        continue
    s = solve(int(line))
    for i in s:
        print(i,end=" ")
    print()

for line in fd:
    print(line)
'''


read_fd = open("/Users/kkhan/Grimaldi/output10.txt")
fd = open("/Users/kkhan/Grimaldi/input10.txt")
fd.readline()
for line in fd:
    s = solve(int(line))
    topline = read_fd.readline()
    t = topline.split()
    for i in range(0,len(s)):
        if s[i] != int(t[i]):
            print("wrong for ",line)
            exit(1)
    else:
        print("Correct for ",line)
