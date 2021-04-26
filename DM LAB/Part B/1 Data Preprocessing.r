data <- read.csv("melanoma.csv")
data

#Checking for NA values & Replacing NA values with average
data$time = ifelse(is.na(data$time),mean(data$time,na.rm=TRUE),data$time)
data$sex = ifelse(is.na(data$sex),mean(data$sex,na.rm=TRUE),data$sex)

# Ensuring all NA values have been replaced
is.na(data$time)
is.na(data$sex)

#Scaling data
data = scale(data)
data