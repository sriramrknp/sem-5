import sys

while(1):
    print("")
    print("1. Create empty set")
    print("2. Insert")
    print("3. Delete")
    print("4. Search")
    print("5. Print")
    print("6. Uninon")
    print("7. Intersection")
    print("8. Set Difference")
    print("9. Symmetric Difference")
    inp = int(input("Choose: "))

    if(inp == 1):
        set1 = set()
        set2 = set()

    elif(inp == 2):
        data = input("Enter the data: ")
        set1.add(data)
    elif(inp == 3):
        data = input("Enter data to be deleted: ")
        if data in set1:
            set1.remove(data)
        else:
            print("The data not found in the set")
    elif(inp == 4):
        data = input("Enter data to be deleted: ")
        #for i in set1:
        if data in set1:
            print("Data found in the set")
        else:
            print("Data not found in the set")

    elif(inp == 5):
        print(set1)

    elif(inp == 6):
        data = input("Enter the data: ")
        set2.add(data)
        uni = set1.union(set2)
        print(uni)

    elif(inp == 7):
        data = input("Enter the data: ")
        set2.add(data)
        uni = set1.intersection(set2)
        print(uni)
        
    elif(inp == 8):
        data = input("Enter the data: ")
        set2.add(data)
        uni = set1.difference(set2)
        print(uni)

    elif(inp == 9):
        data = input("Enter the data: ")
        set2.add(data)
        uni = set1.symmetric_difference(set2)
        print(uni)

    else:
        print("Invalid option choosen")
        sys.exit()
        
    
    
