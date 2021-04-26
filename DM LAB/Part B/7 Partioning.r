library(cluster)

iris_1 <- iris[,-5]

km <- kmeans(iris_1, centers = 3, nstart = 20)

table(iris$Species,km$cluster)

plot(iris_1[c("Sepal.Length","Sepal.Width")],col=km$cluster,main="Kmeans with 3 clusters")