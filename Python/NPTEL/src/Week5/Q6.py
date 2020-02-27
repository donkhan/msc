import random
bins = {}
for i in range(1,11):
    bins[i] = 0
for i in range(1,101):
    r = random.randint(1,10)
    bins[r] = bins[r] + 1

print(bins)

min_ = 0
min_i = -1
for each in bins:
    if bins[each] > min_:
        min_i = each
        min_ = bins[each]
print(min_i)