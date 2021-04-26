library(fpc)
iris_1 <- iris[,-5]

dbscan_cl <- dbscan(iris_1,eps=0.45,MinPts = 4)
dbscan_cl$cluster

table(dbscan_cl$cluster,iris$Species)

plot(iris_1,col=dbscan_cl$cluster,main="DBSCAN")