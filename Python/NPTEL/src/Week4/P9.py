for i in range(1001):
    f = 0
    for j in range(2,i):
        if j * j == i:
            f = 1
            break
    if f == 1:
        print(i)