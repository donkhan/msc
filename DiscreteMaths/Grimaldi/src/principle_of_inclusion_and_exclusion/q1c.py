s1 = s2 = s3 = s4  = 0

for i in range(1,2001):

    if i % 2 != 0:
        s1 = s1 + 1
    if i % 3 != 0:
        s1 = s1 + 1
    if i % 5 != 0:
        s1 = s1 + 1
    if i % 7 == 0:
        s1 = s1 + 1

    if i % 2 != 0 and i % 3 != 0:
        s2 = s2 + 1
    if i % 2 != 0 and i % 5 != 0:
        s2 = s2 + 1
    if i % 2 != 0 and i % 7 == 0:
        s2 = s2 + 1
    if i % 3 != 0 and i % 5 != 0:
            s2 = s2 + 1
    if i % 3 != 0 and i % 7 == 0:
        s2 = s2 + 1
    if i % 5 != 0 and i % 7 == 0:
        s2 = s2 + 1

    if i % 2 != 0 and i % 3 != 0 and i % 5 != 0:
        s3 = s3 + 1
    if i % 2 != 0 and i % 3 != 0 and i % 7 == 0:
        s3 = s3 + 1
    if i % 2 != 0 and i % 5 != 0 and i % 7 == 0:
        s3 = s3 + 1
    if i % 3 != 0 and i % 5 != 0 and i % 7 == 0:
        s3 = s3 + 1

    if i % 2 != 0 and i % 5 != 0 and i % 3 != 0 and i % 7 == 0:
        s4 = s4 + 1

print (2000 - (s1-s2+s3-s4))
