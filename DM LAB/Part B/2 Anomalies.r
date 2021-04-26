data <- iris

summary(data)
head(data)
tail(data)

mean(data$Sepal.Length)
median(data$Sepal.Width)
range(data$Petal.Length)
var(data$Petal.Width)
quantile(data$Sepal.Length)

table(data$Species)

cor(data$Sepal.Length,data$Petal.Length)
cov(data$Sepal.Length,data$Petal.Length)

#Plots
hist(data$Sepal.Length)
plot(density(data$Petal.Width))
pie(table(data$Species),main="Number of Species")
barplot(table(data$Sepal.Length),xlab="Sepal Length",ylab="Frequency")
plot(data$Petal.Length)