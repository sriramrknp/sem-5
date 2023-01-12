li = []

n = int(input("Enter the list size: "))

for i in range(n):
    num = int(input())
    li.append(num)

key = int(input("Enter the key:"))
i = n//2

while(i >= 0 and i <= n-1):
    if(key == li[i]):
        print("Element found at index", i)
        break
    elif(key < li[i]):
        i = i//2
    else:
        i =  i + (n-i)//2
    if(i ==0 | i == n-1):
        if(li[i] != key):
            print("Element not found")
            break


