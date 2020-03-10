def func(i,f):
    print(i)
    if i == 0:
        f = 1
        func(i+1,f)
    if i == 8:
        f = -1
        func(i-1,f)
    if f == 1:
        func(i+1,f)
    if f == -1:
        func(i-1,f)

func(1,1)
