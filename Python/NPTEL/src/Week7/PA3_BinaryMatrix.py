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

flag = "YES"
for i in range(0,rows):
    for j in range(0,cols):
        if mat[i][j] != 1 and mat[i][j] != 0:
            flag = "NO"

print(flag,end="")