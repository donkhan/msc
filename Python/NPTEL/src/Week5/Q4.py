t = []
for i in range(5):
    a = int(input("Enter the No "))
    if len(t) == 0:
        t.append(a)
    else:
        if a > t[len(t)-1]:
            t.append(a)
print(t)