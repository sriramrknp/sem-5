# CS20B1107, SRIRAM REDDY

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix
from sklearn.neighbors import KNeighborsClassifier
from sklearn.preprocessing import MinMaxScaler

df = pd.read_csv('SteelPlateFaults-2class.csv')
print(df.head())
df_test = df.drop(['Class'], axis=1)
X_train, X_test, y_train, y_test = train_test_split(df_test, df['Class'], test_size=0.3, random_state=0)

print("For test data removeing 'Class' attribute")
print(df_test)

print("After splitting the data for test and train")
print(X_train, X_test, y_train, y_test)

model_used = KNeighborsClassifier()
neighList = [1, 3, 5]
print("")

scores = {}
confusion = {}

for neigh in neighList:
    model_used.set_params(n_neighbors=neigh)
    model_used.fit(X_train, y_train)
    scores[neigh] = model_used.score(X_test, y_test)
    y_preds = model_used.predict(X_test)
    confusion[neigh] = confusion_matrix(y_test, y_preds)

maxmum = -1
maxmumNeigh = -1

for neigh in neighList:
    print("")
    print("Neighs = ", neigh)
    print("Confusion Matrix -", confusion[neigh])
    print("Accuracy: ", scores[neigh])

for neigh in neighList:
    if maxmum < scores[neigh] :
        maxmum = scores[neigh]
        maxmumNeigh = neigh

print("")
print("Maximum accuracy is :", maxmum)
print("Max neighbors - ", maxmumNeigh)
print("")

min_maxmum_scaler = MinMaxScaler()
X_train = min_maxmum_scaler.fit_transform(X_train)
X_test = min_maxmum_scaler.fit_transform(X_test)

scores = {}
confusion = {}

for neigh in neighList:
    model_used.set_params(n_neighbors=neigh)
    model_used.fit(X_train, y_train)
    scores[neigh] = model_used.score(X_test, y_test)
    y_preds = model_used.predict(X_test)
    confusion[neigh] = confusion_matrix(y_test, y_preds)

print("After Normalization")

maxmum = -1
maxmumNeigh = -1
for neigh in neighList:
    print("")
    print("Neighs = ", neigh)
    print("Confusion Matrix -", confusion[neigh])
    print("Accuracy :", scores[neigh])

for neigh in neighList:
    if maxmum < scores[neigh]:
        maxmum = scores[neigh]
        maxmumNeigh = neigh

print("")
print("Maximum accuracy is -", maxmum)
print("Max neighbors -", maxmumNeigh)