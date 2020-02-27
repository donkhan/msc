#s1 = input("Enter String...")
#s2 = input("Enter Another String...")

def check(s1,s2):
    for each in list(s1):
        for each2 in list(s2):
            if each == each2:
                print("yes")
                break

check("abc","ab")