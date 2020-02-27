import random

while 1:
    r = random.randint(1,6)
    print(r)
    if r%2 == 0:
        print('Rolling')
        break
    else:
        print("Rolling")