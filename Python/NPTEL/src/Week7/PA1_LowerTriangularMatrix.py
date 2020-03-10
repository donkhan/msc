rows_cols = input().split()
rows = int(rows_cols[0])
cols = int(rows_cols[1])

mat = []

for i in range(0,rows):
    line = input().split()
    row = []
    for j in range(0,cols):
        v = int(line[j])
        row.append(v)
    mat.append(row)

for i in range(0,len(mat)):
    for j in range(0,len(mat[i])):
        if j > i:
            mat[i][j] = 0
    print(mat[i])
