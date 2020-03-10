def min_moves(l):
    sorted_index = { elem : i for i , elem in enumerate(sorted(l))}
    moves = 0
    for idx,elem in enumerate(l):
        if idx != sorted_index[elem] + moves:
            moves = moves + 1
    return moves

l = [ int(i) for i in input().split()]
print(min_moves(l))


