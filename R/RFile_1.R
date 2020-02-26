getwd()
list.files()
setwd("C:/R")
list.files()

read.csv("RPractice.csv")

cricData<-read.csv("RPractice.csv")

fix(cricData)

names(cricData)
mean(cricData$Price)

max(cricData$Price)
min(cricData$Price)

head(cricData)
tail(cricData)

head(cricData,10)
tail(cricData,10)

cor(cricData$Price,cricData$Reserve.Price)

plot(cricData$Price,cricData$Reserve.Price)

plot(cricData$Reserve.Price,cricData$Price)

