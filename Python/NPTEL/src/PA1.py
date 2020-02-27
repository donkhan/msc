def fn(s):
    ones = 0
    zeroes = 0

    for c in s:
        if c == '0':
            zeroes = zeroes + 1
        if c == '1':
            ones = ones + 1

    if ones == 1 or zeroes == 1:
        print("YES")
    else:
        print("NO")


s = input("Enter the Input String....")
fn(s)
