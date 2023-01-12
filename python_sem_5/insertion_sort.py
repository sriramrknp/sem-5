# initilaize the list
li = []

# Taking input of list size
print("Enter the number of digits: ")
n = int(input())

# taking list size elements input
# and appending to the list
for i in range(n):
    num = int(input())
    li.append(num)

num = 0
ind = 0
print(li)

# insertion sort algo
for i in range(n):
    j=i-1
    ele = li[i]
    while(j >=0 and ele < li[j]):
        li[j+1]=li[j]
        j=j-1
    li[j+1]=ele
        

print(li)
    
           
