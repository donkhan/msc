def is_there(_list, f):
    for e in _list:
        if e is f :
            return True
    return False


def shift_add(e, _list, fs):
    for i in range(0, fs-1):
        _list[i] = _list[i + 1]
    _list[fs - 1] = e


def find(frames, fs, debug, book_answer = None):
    print("*************************************************")
    print("Frames ... ", frames, "Frame Size ", fs)
    s = map(int, frames.split(","))
    pf = 0
    q = [None] * fs
    for i in range(0, len(s)):
        if debug:
            print("-----------------")
            print("Accessing ", s[i])
            print(q)
        if is_there(q, s[i]) is False:
            shift_add(s[i], q, fs)
            pf = pf + 1
        if debug:
            print(q)
            print("PF ", pf)
    print("Page Faults ",pf)
    if book_answer is not None:
        print("Book Answer is ",book_answer)
    print("*************************************************")


def main():
    print("1-Custom Input "
          "\n2-SilberChartz Example Problem 1"
          "\n3-SilbarChartz Example Problem-2"
          "\n4-SilberChartz 9.9 Problem")
    choice = input()
    print("Do you want to print the debug steps 1-Yes 2-No")
    flag = input()
    if flag == 1:
        flag = True
    else:
        flag = False
    if choice == 1:
        print("Enter the Frames with comma separation")
        frames = input()
        x = ""
        for i in range(0,len(frames)):
            x = x + str(frames[i]) + ","
        print("Enter Frame Size ")
        fs = input()
        find(x[0:len(x)-1], fs, flag)
    if choice == 2:
        find("7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1", 3, flag, 15)
    if choice == 3:
        find("1,2,3,4,1,2,5,1,2,3,4,5", 3, flag, 9)
        find("1,2,3,4,1,2,5,1,2,3,4,5", 4, flag, 10)
    if choice == 4:
        print("Solution is here https://www.slideshare.net/vtunotesbysree/solution-manual-of-operating-system-concepts-by-abraham-silberschatz-peter-baer-galvin-greg-gagne Page No 32")
        solutions = [20,18,16,14,10,10,7]
        for i in range(1,7):
            find("1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6", i, flag, solutions[i-1])


main()

