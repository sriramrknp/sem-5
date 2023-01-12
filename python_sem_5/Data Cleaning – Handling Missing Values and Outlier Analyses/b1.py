import pandas as pd
import math as mt
import matplotlib.pyplot as plt

df = pd.read_csv('landslide_data3_miss.csv')
dfTemp = pd.read_csv('landslide_data3_miss.csv')
dfA = pd.read_csv('landslide_data3_original.csv')

# 1 - b
prev_len = len(df)
df = df.dropna(subset=["stationid"])
print("Number of tuples deleted in 'stationid'", (prev_len - len(df)))

prev_len = len(df)
df = df.dropna(thresh=6)
print("Number of tuples deleted", (prev_len - len(df)))

# 1 - c
print("Number of missing values in each attribute")
print(df.isnull().sum())

miss = dfTemp.isnull().sum()
li_miss = []
for i in miss.items():
    li_miss.append(i[1])
print(li_miss)

count = 0
for i in range(len(df.index)):
    count += df.iloc[i].isnull().sum()
print("Total number of missing values in the file", count)

# 2 a
print("")
mean_mis = df.mean(axis=0, numeric_only=True, skipna=True)

miss = df.isnull().sum()
li_miss_ = []
for i in miss.items():
    li_miss_.append(i[1])
print(li_miss_)

for item in mean_mis.items():
    if (item[0] == "temperature"):
        df.fillna({'temperature': item[1]}, inplace=True)

    elif (item[0] == "humidity"):
        df.fillna({'humidity': item[1]}, inplace=True)

    elif (item[0] == "pressure"):
        df.fillna({'pressure': item[1]}, inplace=True)

    elif (item[0] == "rain"):
        df.fillna({'rain': item[1]}, inplace=True)

    elif (item[0] == "lightavgw/o0"):
        df.fillna({'lightavgw/o0': item[1]}, inplace=True)

    elif (item[0] == "lightmax"):
        df.fillna({'lightmax': item[1]}, inplace=True)

    elif (item[0] == "moisture"):
        df.fillna({'moisture': item[1]}, inplace=True)

print("")
print("Mean of attributes miss vs original")
mean_mis = df.mean(axis=0, numeric_only=True, skipna=True)
print(mean_mis)
mean_mis = dfA.mean(axis=0, numeric_only=True, skipna=True)
print(mean_mis)

print("")
print("Mode of attributes miss vs original")
mean_mis = df.mode(axis=0, numeric_only=True)
print(mean_mis)
mean_mis = dfA.mode(axis=0, numeric_only=True)
print(mean_mis)

print("")
print("Median of attributes miss vs original")
mean_mis = df.median(axis=0, numeric_only=True, skipna=True)
print(mean_mis)
mean_mis = dfA.median(axis=0, numeric_only=True, skipna=True)
print(mean_mis)

print("")
print("SD of attributes miss vs original")
mean_mis = df.std(axis=0, numeric_only=True, skipna=True)
print(mean_mis)
mean_mis = dfA.std(axis=0, numeric_only=True, skipna=True)
print(mean_mis)

print("")
li = []

li_inter = []
li_ori = []
for (columnName, columnData) in df.items():
    if (columnName == "temperature"):
        li_inter.append(columnData)

    elif (columnName == "humidity"):
        li_inter.append(columnData)

    elif (columnName == "pressure"):
        li_inter.append(columnData)

    elif (columnName == "rain"):
        li_inter.append(columnData)

    elif (columnName == "lightavgw/o0"):
        li_inter.append(columnData)

    elif (columnName == "lightmax"):
        li_inter.append(columnData)

    elif (columnName == "moisture"):
        li_inter.append(columnData)

for (columnName, columnData) in dfA.items():
    if (columnName == "temperature"):
        li_ori.append(columnData)

    elif (columnName == "humidity"):
        li_ori.append(columnData)

    elif (columnName == "pressure"):
        li_ori.append(columnData)

    elif (columnName == "rain"):
        li_ori.append(columnData)

    elif (columnName == "lightavgw/o0"):
        li_ori.append(columnData)

    elif (columnName == "lightmax"):
        li_ori.append(columnData)

    elif (columnName == "moisture"):
        li_ori.append(columnData)

li_rmse = []
ind = 2
for i in range(0, len(li_inter)):
    sum = 0.0
    for j in range(0, len(li_inter[i])):
        try:
            sum += pow((li_inter[i][j]-li_ori[i][j]), 2)
        except KeyError:
            continue

    li_rmse.append(mt.sqrt(sum//li_miss_[ind]))
    ind = ind + 1
print("RMSE of Mean")
print(li_rmse)

names = ["temperature", "humidity", "pressure",
         "rain", "lightavgw/o0", "lightmax", "moisture"]
plt.bar(names, li_rmse)
plt.show()
print("")

# 2 b

print("")
print(dfTemp)
df_inter = dfTemp.interpolate(method='linear')
print(df_inter)

print("")
print("Mean of attributes miss vs original")
mean_mis = df_inter.mean(axis=0, numeric_only=True, skipna=True)
print(mean_mis)
mean_mis = dfA.mean(axis=0, numeric_only=True, skipna=True)
print(mean_mis)

print("")
print("Mode of attributes miss vs original")
mean_mis = df_inter.mode(axis=0, numeric_only=True)
print(mean_mis)
mean_mis = dfA.mode(axis=0, numeric_only=True)
print(mean_mis)

print("")
print("Median of attributes miss vs original")
mean_mis = df_inter.median(axis=0, numeric_only=True, skipna=True)
print(mean_mis)
mean_mis = dfA.median(axis=0, numeric_only=True, skipna=True)
print(mean_mis)

print("")
print("SD of attributes miss vs original")
mean_mis = df_inter.std(axis=0, numeric_only=True, skipna=True)
print(mean_mis)
mean_mis = dfA.std(axis=0, numeric_only=True, skipna=True)
print(mean_mis)

print("")
print("")


li_inter = []
li_ori = []
for (columnName, columnData) in df_inter.items():
    if (columnName == "temperature"):
        li_inter.append(columnData)

    elif (columnName == "humidity"):
        li_inter.append(columnData)

    elif (columnName == "pressure"):
        li_inter.append(columnData)

    elif (columnName == "rain"):
        li_inter.append(columnData)

    elif (columnName == "lightavgw/o0"):
        li_inter.append(columnData)

    elif (columnName == "lightmax"):
        li_inter.append(columnData)

    elif (columnName == "moisture"):
        li_inter.append(columnData)

for (columnName, columnData) in dfA.items():
    if (columnName == "temperature"):
        li_ori.append(columnData)

    elif (columnName == "humidity"):
        li_ori.append(columnData)

    elif (columnName == "pressure"):
        li_ori.append(columnData)

    elif (columnName == "rain"):
        li_ori.append(columnData)

    elif (columnName == "lightavgw/o0"):
        li_ori.append(columnData)

    elif (columnName == "lightmax"):
        li_ori.append(columnData)

    elif (columnName == "moisture"):
        li_ori.append(columnData)

li_rmse = []
ind = 2
for i in range(0, len(li_inter)):
    sum = 0.0
    for j in range(0, len(li_inter[i])):
        sum += pow(li_inter[i][j]-li_ori[i][j], 2)

    li_rmse.append(mt.sqrt(sum//li_miss[ind]))
    ind = ind + 1
print("RMSE of interpolate")
print(li_rmse)

names = ["temperature", "humidity", "pressure",
         "rain", "lightavgw/o0", "lightmax", "moisture"]
plt.bar(names, li_rmse)
plt.show()
print("")
