def min_moves(l):
    print(l)
    sorted_index = { elem : i for i , elem in enumerate(sorted(l))}
    moves = 0
    for idx,elem in enumerate(l):
        if idx != sorted_index[elem] + moves:
            moves = moves + 1
    return moves

print(min_moves([5,1,3,2,7]))
