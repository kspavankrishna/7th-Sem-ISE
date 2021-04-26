library(randomForest)
library(party)
library(caret)

data <- iris
index <- sample(2,nrow(data),replace = TRUE,p=c(0.7,0.3))
 trainData <- data[index==1,]
testData <- data[index==2,] 

features <- Species ~ Petal.Length + Petal.Width + Sepal.Length+ Sepal.Width

#RANDOM FOREST
model1 <- randomForest(features,trainData)
res <- predict(model1,testData)
confusionMatrix(res,testData$Species)