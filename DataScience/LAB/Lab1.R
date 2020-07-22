print("Welcome to R")

# Arithmetic Operators 
# Add,Sub,Mul,Div,Mod

cat(2 + 3)
cat(2 - 4)
cat(2 * 5)
cat(25 / 5)
cat(23 %% 3)

a = 3
b = 5
c = a + b

print(c[1])

#Vectors

v = c(1,2,3)
v = v + 13
print(v[1])


# indexing and Slicing
v = 1:100
print(v[34])
print(v[5:30])

# Squares
N = 1:10
print(N * N)


# Arrays
# Creation of 3D array
r = array(c(1:10,11:20),dim=c(3,3,2))
print(r)


# Row names and col names
r = array(c(1:200),dim=c(3,3,2),dimnames=list(c("C1","C2","C3"),c("R1","R2","R3")))
print(r)


# Accessing Array
# Example 3rd row of the second matrix

print(r[3,,2])

#Element of 1st row, 3rd col of 1st matrix
print(r[1,3,1])


# Manipulating Array
r[1,3,1] = 17
print(r[1,3,1])
r[1,3,1] = 7


# Calculations across array elements using array elements
v1 = c(5,9,3)
v2 = c(10,11,12,13,14,15)


array = array(c(v1,v2),dim=c(3,3,1))
print(array)

# Apply (array,vector of margin, function)
# Following command is Row wise addition
print(apply(array,c(1),sum))

# Following command is Column wise addition
print(apply(array,c(2),sum))

# Mean - Column wise
print(apply(array,c(2),mean))

# Built in functions - (mean,median,sum,min,max)

print(apply(array,c(1),max))

#User Defined Function

mean_deviation = function(v){
  m = mean(v)
  md = sum(v-m)/length(v)
}

print(apply(array,c(1),function(x) mean_deviation(x)))


#Functions
# sum 1 to 5
print(sum(1:5))
print(sum(1:10000))
print(seq(2,30,5))


# Matrices
mat = matrix(1:9,nrow=3,ncol=3)
print(mat)

print(nrow(mat))
print(ncol(mat))


# Max of Second Column
print(max(mat[,2]))

# Min of 3rd Row
print(min(mat[3,]))

#Standard Deviation of 3rd Row
print(sd(mat[3,]))


#Sub setting
# 2 to 3 rd row, 1st column
print(mat[2:3,1])

# apply. Standard deviation of each row

print(apply(mat,c(1),sd))














