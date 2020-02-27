def find(l,num):
    for each in l:
        if each != num:
            print(each)
        else:
            break

t = []
for i in range(10):
    t.append(i)

find(t,9)