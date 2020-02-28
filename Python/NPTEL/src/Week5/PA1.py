import math
N,v1,v2 = map(int,input().split())
walk = N * math.sqrt(2) / v1
cab = 2*N / v2

if walk < cab:
    print("Walk")
else:
    print("Cab")
