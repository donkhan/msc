import random

p1 = ['rock','paper','scissor']
p2 = ['rock','paper','scissor']

c1 = random.choice(p1)
c2 = random.choice(p1)

if c1 == c2:
    print("SUCCESS")
else:
    print("FAILURE")