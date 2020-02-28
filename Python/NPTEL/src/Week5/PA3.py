def is_prime(n):
    x = int(n/2) + 1
    for i in range(2,x):
        if n % i == 0:
            return False
    return True


def is_semi_prime(n):
    for i in range(2,int(n/2)+1):
        if n % i == 0:
            x = i
            y = int(n/i)
            if x != y:
                if is_prime(x) and is_prime(y):
                    return True
    return False

def our_problem(n):
    for i in range(1,int(n/2)+1):
        x = i
        y = n - i
        if is_semi_prime(x) and is_semi_prime(y):
            return True
    return False

n = int(input())
if our_problem(n):
    print("Yes",end="")
else:
    print("No",end="")
