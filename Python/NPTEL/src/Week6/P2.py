def guess(num):
    a = input("Guess a Number ")
    if a == num:
        print("SUCCESS")
    else:
        guess(num)

guess(10)