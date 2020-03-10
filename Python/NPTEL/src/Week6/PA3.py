
N = int(input())
def printDic():
    d = {}
    for i in range(1,N+1):
        d[i] = i*i

    print(d,end="")

printDic()