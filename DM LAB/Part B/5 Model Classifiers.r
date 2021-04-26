library(rpart)
library(caret)
library(e1071)
library(rpart.plot)

data <- iris
index <- sample(2,nrow(data),replace=TRUE,p=c(0.7,0.3))
trainData <- data[index==1,]
testData <- data[index==2,]

#Y vs x
features <- Species ~ Sepal.Length + Sepal.Width + Petal.Length + Petal.Width

#Decision Tree
tree1 <- ctree(features,trainData)
plot(tree1)

#Decision Tree Prediction
res1 <- predict(tree1,testData)
confusionMatrix(res1,testData$Species)

#Naive Bayes
model1 <- naiveBayes(features,trainData)
print(model1)

#Naive Bayes Prediction
res2 <- predict(model1,testData)
confusionMatrix(res2,testData$Species)