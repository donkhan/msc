import random

movies = ["3idiots","chinatown","conjuring","avengers","titanic"]
ch = random.choice(movies)
print(ch)
for i in range(len(ch)):
    print("-",end="")