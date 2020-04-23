
def fact(n):
    if n == 1:
        return 1
    return n * fact(n-1)

def npr(n,r):
    return fact(n)/fact(n-r)

def ncr(n,r):
    return fact(n)/(fact(n-r) * fact(r))



