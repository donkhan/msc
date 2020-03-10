def func(i):
    print(i)
    if i > 128:
        print (" OVER ")
    else:
        func(i * 2)

func(1)