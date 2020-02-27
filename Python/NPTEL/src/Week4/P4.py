def leap(year):
    if year % 400 == 0 or (year % 100 != 0 and year%4 == 0):
        return True
    return False

print(leap(2000))
print(leap(1900))
print(leap(1996))
print(leap(1997))