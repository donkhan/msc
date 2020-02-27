import random
bins = {}
for i in range(1,11):
    bins[i] = 0
for i in range(1,101):
    r = random.randint(1,10)
    bins[r] = bins[r] + 1

print(bins)

