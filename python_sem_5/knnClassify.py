## Nischal Pradyoth 
## CS20B1109
## Inference: I understood that after doing min max normalization 
# the model is able to understand more clearly as the range decreases (0-1), so this is a good practice for prediction
import numpy as np 
import pandas as pd 
import matplotlib.pyplot as plt 

from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import confusion_matrix
from sklearn.preprocessing import MinMaxScaler

df=pd.read_csv("SteelPlateFaults-2class.csv")

y=df['Class']
x=df.drop("Class",axis=1)

X_train,X_test,y_train,y_test=train_test_split(x,y,test_size=0.3,shuffle=True,random_state=42)

model=KNeighborsClassifier()

neighbors_list=[1,3,5]
scores={}
confusion={}

print("Initially the results are as follows:")
### 1
for neighbor in neighbors_list:
    model.set_params(n_neighbors=neighbor)
    model.fit(X_train,y_train)
    scores[neighbor]=model.score(X_test,y_test)
    y_preds=model.predict(X_test)
    confusion[neighbor]=confusion_matrix(y_test,y_preds)

##printing results
max=-1 
max_neighbor=-1
for neighbor in neighbors_list:
    print(f"The details of model with neighbors={neighbor}")
    print("Accuracy:",scores[neighbor])
    if(max<scores[neighbor]):
        max=scores[neighbor]
        max_neighbor=neighbor
    print("Confusion Matrix:\n",confusion[neighbor])

print(f"So the maximum accuracy is : {max} with neighbors= {max_neighbor}")

### 2
min_max_scaler = MinMaxScaler()
X_train = min_max_scaler.fit_transform(X_train)
X_test = min_max_scaler.fit_transform(X_test)

neighbors_list=[1,3,5]
scores={}
confusion={}

for neighbor in neighbors_list:
    model.set_params(n_neighbors=neighbor)
    model.fit(X_train,y_train)
    scores[neighbor]=model.score(X_test,y_test)
    y_preds=model.predict(X_test)
    confusion[neighbor]=confusion_matrix(y_test,y_preds)

##printing results
print("After doing Min max normalization, the results are:")
max=-1
max_neighbor=-1
for neighbor in neighbors_list:
    print(f"The details of model with neighbors={neighbor}")
    print("Accuracy:",scores[neighbor])
    if(max<scores[neighbor]):
        max=scores[neighbor]
        max_neighbor=neighbor
    print("Confusion Matrix:\n",confusion[neighbor])

print(f"So the maximum accuracy is : {max} with neighbors= {max_neighbor}")