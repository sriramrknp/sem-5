import pandas as pd
import matplotlib.pyplot as plt
import sys

df = pd.read_csv('diabetes1.csv')

'''
# Pregnancies
mean_p = 0
mean_p += df['Pregnancies']
print("Pregnancies")
print("Mean", mean_p.mean())
print("Median", mean_p.median())
print("Mode", mean_p.mode())
print("Min", mean_p.min())
print("Max", mean_p.max())
print("STD", mean_p.std())

# Glucose
mean_p = 0
mean_p += df['Glucose']
print("")
print("Glucose")
print("Mean", mean_p.mean())
print("Median", mean_p.median())
print("Mode", mean_p.mode())
print("Min", mean_p.min())
print("Max", mean_p.max())
print("STD", mean_p.std())

# BloodPressure
mean_p = 0
mean_p += df['BloodPressure']
print("")
print("BloodPressure")
print("Mean", mean_p.mean())
print("Median", mean_p.median())
print("Mode", mean_p.mode())
print("Min", mean_p.min())
print("Max", mean_p.max())
print("STD", mean_p.std())

# SkinThickness
mean_p = 0
mean_p += df['SkinThickness']
print("")
print("SkinThickness")
print("Mean", mean_p.mean())
print("Median", mean_p.median())
print("Mode", mean_p.mode())
print("Min", mean_p.min())
print("Max", mean_p.max())
print("STD", mean_p.std())

# Insulin
mean_p = 0
mean_p += df['Insulin']
print("")
print("Insulin")
print("Mean", mean_p.mean())
print("Median", mean_p.median())
print("Mode", mean_p.mode())
print("Min", mean_p.min())
print("Max", mean_p.max())
print("STD", mean_p.std())

# BMI
mean_p = 0
mean_p += df['BMI']
print("")
print("BMI")
print("Mean", mean_p.mean())
print("Median", mean_p.median())
print("Mode", mean_p.mode())
print("Min", mean_p.min())
print("Max", mean_p.max())
print("STD", mean_p.std())

# DiabetesPedigreeFunction
mean_p = 0
mean_p += df['DiabetesPedigreeFunction']
print("")
print("DiabetesPedigreeFunction")
print("Mean", mean_p.mean())
print("Median", mean_p.median())
print("Mode", mean_p.mode())
print("Min", mean_p.min())
print("Max", mean_p.max())
print("STD", mean_p.std())

# Age
mean_p = 0
mean_p += df['Age']
print("")
print("Age")
print("Mean", mean_p.mean())
print("Median", mean_p.median())
print("Mode", mean_p.mode())
print("Min", mean_p.min())
print("Max", mean_p.max())
print("STD", mean_p.std())

print("")
print("Scatter Plot of Age vs all other attributes")
print("Age vs Pregnancies", df.plot.scatter(x='Age', y='Pregnancies'))
plt.show()
print("Age vs Glucose", df.plot.scatter(x='Age', y='Glucose'))
plt.show()
print("Age vs BloodPressure", df.plot.scatter(x='Age', y='BloodPressure'))
plt.show()
print("Age vs SkinThickness", df.plot.scatter(x='Age', y='SkinThickness'))
plt.show()
print("Age vs Insulin", df.plot.scatter(x='Age', y='Insulin'))
plt.show()
print("Age vs BMI", df.plot.scatter(x='Age', y='BMI'))
plt.show()
print("Age vs DiabetesPedigreeFunction", df.plot.scatter(
    x='Age', y='DiabetesPedigreeFunction'))
plt.show()


print("")
print("Scatter Plot of BMI vs all other attributes")
print("BMI vs Pregnancies", df.plot.scatter(x='BMI', y='Pregnancies'))
plt.show()
print("BMI vs Glucose", df.plot.scatter(x='BMI', y='Glucose'))
plt.show()
print("BMI vs BloodPressure", df.plot.scatter(x='BMI', y='BloodPressure'))
plt.show()
print("BMI vs SkinThickness", df.plot.scatter(x='BMI', y='SkinThickness'))
plt.show()
print("BMI vs Insulin", df.plot.scatter(x='BMI', y='Insulin'))
plt.show()
print("BMI vs BMI", df.plot.scatter(x='BMI', y='DiabetesPedigreeFunction'))
plt.show()
print("BMI vs DiabetesPedigreeFunction", df.plot.scatter(x='Age', y='Age'))
plt.show()
'''
print("")
print("Pregnancies histogram with Skinthickness")
hist_pregne_skin = df[["Pregnancies", "SkinThickness"]].hist()
plt.show()

print("")
print("Pregnancies histogram with Outcome")
hist_outcome = df.plot.hist(column=["Pregnancies"], by=["Outcome"])
plt.show()
'''
print("")
print("Boxplot")
plt.boxplot(df["Pregnancies"])
plt.title("Pregnancies")
plt.show()

plt.boxplot(df["Glucose"])
plt.title("Glucose")
plt.show()

plt.boxplot(df["BloodPressure"])
plt.title("BloodPressure")
plt.show()

plt.boxplot(df["SkinThickness"])
plt.title("SkinThickness")
plt.show()

plt.boxplot(df["Insulin"])
plt.title("Insulin")
plt.show()

plt.boxplot(df["BMI"])
plt.title("BMI")
plt.show()

plt.boxplot(df["DiabetesPedigreeFunction"])
plt.title("DiabetesPedigreeFunction")
plt.show()

plt.boxplot(df["Age"])
plt.title("Age")
plt.show()
'''
