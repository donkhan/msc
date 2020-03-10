import random
def guess(num):
    print("N " ,num)
    a = int(input("Guess a Number "))
    if a == num:
        print("SUCCESS")
    else:
        guess(random.randint(1,100))

i = guess(random.randint(1,100))