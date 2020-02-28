import math
a = input().split()

N = int(a[0])
v1 = int(a[1])
v2 = int(a[2])

walk = N * math.sqrt(2) / v1
cab = 2*N / v2

if walk < cab:
    print("Walk")
else:
    print("Cab")
