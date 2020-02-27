r = int(input("Enter R..."))
c = int(input("Enter C..."))
k = 1
for i in range(0,r):
    for j in range(0,c):
        if j != c-1:
            print(k,end=" ")
        elif i != r-1:
            print(k,end="\n")
        else:
            print(k,end="")
        k = k + 1
