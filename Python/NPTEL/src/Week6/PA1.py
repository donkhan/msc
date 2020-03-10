def find_computing_paradox_loc(l,computing_paradox_loc):
    play_list = []
    for each in l:
        play_list.append(int(each))
    computing_paradox = play_list[computing_paradox_loc-1]
    play_list = sorted(play_list)

    for i in range(0, len(play_list)):
        if play_list[i] == computing_paradox:
            print(i+1, end=" ")
            break

N = int(input())
l = input().split()
cp = int(input())

find_computing_paradox_loc(l,cp)

#find_computing_paradox_loc(['1','3','4','2'],2)
#find_computing_paradox_loc(['1','2','3','9','4'],5)
#find_computing_paradox_loc(['1','2','3','9','4'],1)
#find_computing_paradox_loc(['1','3','5','2','4','6'],3)


