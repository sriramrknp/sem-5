# CS20B1107, SRIRAM REDDY CHEERLA

import sys

def write():
    file = open('fileLib.txt', 'a+')
    print("Enter Num of books you want to enter")
    n = int(input())
    while(n >= 1):
        file.write("\n")
        print("Enter the details of the book")
        print("Details: ISSN, title, price, edition, year, author")
        s = input()
        file.write(s)
        n = n-1
    file.close()

def read():
    f = open('fileLib.txt', 'r+')
    print(f.read())
    f.close()

def search():
    f = open('fileLib.txt', 'r+')
    li = f.readlines()
    str = input("Eter the book name to search: ")
    for i in li:
        if str in i:
            print("Yes")
            print("Details: ISSN, title, price, edition, year, author")
            print(i)
            return
    else:
        print("No")
    f.close()
    

while(1):
    print("1. Write")
    print("2. Read")
    print("3. Search")
    print("4. Exit")
    opt = float(input("Enter option: "))
    opt = int(opt)
    
    if(opt == 1):
        write()
    elif(opt == 2):
        read()
    elif(opt == 3):
        search()
    elif(opt == 4):
        sys.exit()
