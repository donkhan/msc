# Creating Data Frame

#First we create the vectors

c(1,2,3,4) -> Number
c("Poor","Poor","Good","Good") -> Diet
c("M","F","M","F") -> Sex
c(156,180,167,190) -> Weight
c(34,43,40,43  ) -> Fat.Content
c("Winged","Winged","Wingless","Intermediate") -> Morph

data.frame(Number,Diet,Sex,Weight,Fat.Content,Morph) -> crickets

list(Number,Diet,Sex,Weight,Fat.Content,Morph) -> crickets.list


# difference between list and data frames

c(156,180,167,NA) -> Weight
data.frame(Number,Diet,Sex,Weight,Fat.Content,Morph) -> crickets
list(Number,Diet,Sex,Weight,Fat.Content,Morph) -> crickets.list

mean(crickets$Weight,na.rm=TRUE)


