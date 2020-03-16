def func():
    print()
    c = 10
    i = 3
    while i <= 6:
        j = 0
        while j <= 20:
            if j >= 10-i and j <= 10+i:
                print("*",end = " ")
            else:
                print(" ",end = " ")
            j = j + 1
        print("\n")
        i = i + 1

    i = 6
    while i >= 3:
        j = 0
        while j<= 20:
            if j >= 10 - i and j <= 10 + i:
                print("*", end=" ")
            else:
                print(" ", end=" ")
            j = j + 1
        print("\n")
        i = i - 1
    
func()
