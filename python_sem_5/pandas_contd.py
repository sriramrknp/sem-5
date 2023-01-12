import pandas as pd
import sys

df = pd.read_csv('diabetes.csv')

while(1):
    print("")
    print("1. Find the probability of diabetes given the dataset")
    print("2. Probability of of diabeties of age above 50")
    print("3. Probability of of diabeties of age above 50")
    print("4. Probability of of diabeties of age above 50")
    print("5. Probability of of diabeties of age above 50")
    print("6. Find the probability of diabetes with a glucose level of more than 120 + blood pressure of more than 90 + skin thickness of more than 30 + insulin above 150 + BMI above 25")
    
    inp = int(input("Enter the option: "))
    print("")
    
    if(inp == 1):
        sum = 0
        ind = df[df['Outcome'] == 1].index
        sum += df['Outcome'][ind]
        
        print(sum.size)
        print(len(df.index))
        print("Probability of given data set")
        print(sum.size / len(df.index))
    
    elif(inp == 2):
        
        sum1 = df[df['Age'] > 50].index
        sample_space = 0
        sample_space += df['Outcome'][sum1]
        
        age50 = sample_space.size
        
        sum1 = df[(df['Age'] > 50) & (df['Outcome'] == 1)].index
        sample_space = 0
        sample_space += df['Outcome'][sum1]
        
        print(sample_space.size / age50)
        
    elif(inp == 3):
        sum1 = df[(df['Age'] > 40) & (df['Age'] < 50)].index
        sample_space = 0
        sample_space += df['Outcome'][sum1]
        
        age40and50 = sample_space.size
        
        sum1 = df[((df['Age'] > 40) & (df['Age'] < 50)) & (df['Outcome'] == 1)].index
        sample_space = 0
        sample_space += df['Outcome'][sum1]
        
        print(age40and50)
        print(sample_space.size)
        print(sample_space.size / age40and50)
        
    elif(inp == 4):
        sum1 = df[(df['Age'] > 30) & (df['Age'] < 40)].index
        sample_space = 0
        sample_space += df['Outcome'][sum1]
        
        age40and50 = sample_space.size
        
        sum1 = df[((df['Age'] > 30) & (df['Age'] < 40)) & (df['Outcome'] == 1)].index
        sample_space = 0
        sample_space += df['Outcome'][sum1]
        
        print(age40and50)
        print(sample_space.size)
        print(sample_space.size / age40and50)
        
    elif(inp == 5):
        sum1 = df[(df['Age'] < 30)].index
        sample_space = 0
        sample_space += df['Outcome'][sum1]
        
        age40and50 = sample_space.size
        
        sum1 = df[(df['Age'] < 30) & (df['Outcome'] == 1)].index
        sample_space = 0
        sample_space += df['Outcome'][sum1]
        
        print(age40and50)
        print(sample_space.size)
        print(sample_space.size / age40and50)
        
    elif(inp == 6):
        sum1 = df[(df['Glucose'] > 120) & (df['BloodPressure'] > 90) & (df['SkinThickness'] > 30) & (df['Insulin'] > 150) & (df['BMI'] > 25)].index
        sample_space = 0
        sample_space += df['Outcome'][sum1]
        
        age40and50 = sample_space.size
        
        sum1 = df[(df['Glucose'] > 120) & (df['BloodPressure'] > 90) & (df['SkinThickness'] > 30) & (df['Insulin'] > 150) & (df['BMI'] > 25) & (df['Outcome'] == 1)].index
        sample_space = 0
        sample_space += df['Outcome'][sum1]
        
        print(age40and50)
        print(sample_space.size)
        print(sample_space.size / age40and50)
    elif(inp == 7):
        exit()
