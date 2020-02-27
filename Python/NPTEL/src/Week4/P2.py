
l1 = ["apple","banana","kiwi","orange"]
l2 = ["watermelon","melon","kiwi","banana"]
cmn = []

for i in range(4):
    if l1[i] == l2[i]:
        cmn.append(l1[i])
print(cmn)