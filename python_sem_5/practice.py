import pandas as pd
from os import remove
import numpy as np

li=[]
li=[1,2,3,4,5,6,7,8]
'''
print(li)
print(max(li))
print(min(li))
print(li.pop())
print(li.pop(1))
print(li)

li1 = [11,12,13]
li3 = li + li1
print(li3)
'''
'''
del li[1]
print(li)

tu = (1,2,3,4)
print(tu)
print(max(tu))
tu = tu[2:]
print(tu)

'''
'''
di = {'Name': ["BatMan", "AMD"], 'Age': 20}
print(di)
print(di['Name'][1])
print(di.keys())
print(di.values())

for i in di.keys():
    print(i)
'''
'''
se = {7,2,3,4}
print(se)
for i in se:
    print(i, end=" ")
print("")
num = se.pop()
print(num)
'''

'''
arr = np.array([3,2])
arr2d = np.array([[3, 2], [4,5]])
print(arr2d[0][1])
'''

l1 = ["Ram", "Sam", "Prabhu"]
l2 = [9893893891, 9893893898, 9893893871]
l3 = ["SB", "CA", "SB"]
l4 = [959389389173, 959389389179, 959389389159]
l5 = [8989839, 7690990, 989330]

d1 = {'Name': l1, 'Account Number': l2,
      'Account Type': l3, 'Aadhar_No': l4, 'Balance': l5}

df1 = pd.DataFrame(d1)
df1.to_csv("SBIAccountHolder.csv")

print(df1[df1['Account Number'] == 9893893891].index)
ind = df1[df1['Account Number'] == 9893893891].index
df1['Balance'][ind] += 1
df1.to_csv("SBIAccountHolder.csv")
print(df1[df1['Account Number'] == 9893893891])
