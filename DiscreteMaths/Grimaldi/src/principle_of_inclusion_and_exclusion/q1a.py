

S1 = S2 = S3 = S4 = S5 = S6 = S7 = 0
for i in range(1,2001):
    if i % 2 == 0:
        S1 = S1 + 1
    if i % 3 == 0:
        S2 = S2 + 1
    if i % 5 == 0:
        S3 = S3 + 1
    if i % 6 == 0:
        S4 = S4 + 1
    if i % 10 == 0:
        S5 = S5 + 1
    if i % 15 == 0:
        S6 = S6 + 1
    if i % 30 == 0:
        S7 = S7 + 1

print(2000- (S1+S2+S3 - (S4+S5+S6) + S7))
