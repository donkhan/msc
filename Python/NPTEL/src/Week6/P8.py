def func(i):
    print(i)
    if i == 0:
        print (" OVER ")
    else:
        func(i/2)

func(100)