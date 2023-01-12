import pickle as pi
import sys

f1 = open("file.dat", "wb+")

while (1):
    print("1. Print all the records with the destination")
    print("2. Append record")
    print("3. Total ticket price")
    print("")
    op = int(input("Enter the option: "))

    if (op == 1):
        f = open("file.dat", 'rb')

        dt = []
        with open("file.dat", 'rb') as fr:
            try:
                while True:
                    dt.append(pi.load(fr))
            except EOFError:
                pass
        f.close()
        print(dt)

        print("Enter the destination")
        des = input()

        for i in range(0, len(dt)):
            if des in dt[i][5]:
                print(dt[i])
        continue

    elif (op == 2):
        f = open("file.dat", "ab")
        li = []
        print("Enter the Name of passenger")
        name = input()
        li.append(name)
        print("Enter the Booking date")
        date = input()
        li.append(date)
        print("Enter the Coach number")
        coach = input()
        li.append(coach)
        print("Enter the Seat")
        seat = int(input())
        li.append(seat)
        print("Enter the source")
        source = input()
        li.append(source)
        print("Enter the destination")
        des = input()
        li.append(des)
        print("Enter the Ticket price")
        price = float(input())
        li.append(price)
        pi.dump(li, f)
        f.close()

    elif (op == 3):
        f = open("file.dat", 'rb')

        dt = []
        with open("file.dat", 'rb') as fr:
            try:
                while True:
                    dt.append(pi.load(fr))
            except EOFError:
                pass
        f.close()
        print(dt)
        num = 0
        for i in range(0, len(dt)):
            num += dt[i][6]
        print("Total Ticket price sum")
        print(num)

    else:
        sys.exit()
f1.close()