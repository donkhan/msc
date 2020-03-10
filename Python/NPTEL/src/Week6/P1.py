def encrypt(ltr,key):
    l = []
    for each in list(ltr):
        l.append(chr(ord(each) + 1))
    return "".join(l)

letter_body = "ABCDEFGH"
d = encrypt(letter_body,4)
print(d)