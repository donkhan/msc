def mul(num):
    if num == 1:
        return -1
    else:
        return -1 * mul(num-1)

n = int(input("Enter  the value of n "))
print(mul(n))