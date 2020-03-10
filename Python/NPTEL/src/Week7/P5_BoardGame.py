import random

def play(psn):
    r = random.randint(1,6)
    print("Dice Rolled ",r)
    input()
    if psn == 0:
        if r == 1 or  r == 6:
            psn = 1
    else:
        psn = psn + r
    if psn >= 100:
        print("You Won ")
        return
    play(psn)

position = 0
print(" Position = ",position)
play(position)