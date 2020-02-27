
def a1(p):
    while p > 0:
        p = p + 2
        print(" L " ,p)
        p = p - 4
        print(" L " , p)
    print("Fell in Location ", p)


def a3(p):
    while p > 0:
        for i in range(2):
            p = p + 1
            if  p == 0:
                break
        for i in range(4):
            p = p - 1
            if p == 0:
                break
        print("Fell into pit")

for i in range(100):
    a3(i)




