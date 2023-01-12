import sys

#initilizied dictionary
dict={}

# loop runs untill you exit from the program
while(1):
    # menu
    print("1. Insert in dict")
    print("2. Delete")
    print("3. Search")
    print("4. Exit")
    opt = int(input("Choose: "))

    if(opt == 1):
        li=[]
        key = input("Enter the Roll Num: ")
        for i in range(3):
            if(i == 0):
                print("Enter the name of student")
                name = input()
                li.append(name)
            elif(i == 1):
                print("Enter the CGPA of student")
                gpa = input()
                li.append(gpa)
            elif(i == 2):
                print("Enter the mobile num of student")
                mobile = input()
                li.append(mobile)
        dict[key] = li
        
    elif(opt == 2):
        
        roll = input("Enter the roll num to delete: ")
        if roll in dict.keys():
            del dict[roll]
        else:
             print("The entered key is not present in dictionary")
        
    elif(opt == 3):
        roll = input("Enter the roll num to delete: ")
        if roll in dict.keys():
            print("The key is found in dict")
        else:
            print("The entered key is not present in dictionary")

    elif(opt == 4):
        sys.exit()
    else:
        print("Invalid option")
    
