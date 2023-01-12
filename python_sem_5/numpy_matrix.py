import numpy as np
import sys

print("Enter the size of Row: ")
r = int(input())
print("Enter the size of Clm: ")
c = int(input())

a = np.zeros((r,c))
b = np.zeros((r,c))

print("Enter the elements in matrix 1")
for i in range(r):
    print("Enter the ", c, " elements ")
    for j in range(c):
        num = int(input())
        a[i][j] = num

print("ENter the elements in matrix 1")
for i in range(r):
    print("Enter the ", c, " elements ")
    for j in range(c):
        num = int(input())
        b[i][j] = num

print(a)
print(b)

while(1):
    print("")
    print("1. Addition")
    print("2. Substraction")
    print("3. Scalar Matrix Multiplication")
    print("4. Elementwise Matrix Multiplication")
    print("5. Matrix Mul")
    print("6. Matrix Transpose")
    print("7. Trace of Matrix")
    print("8. Solve sys of linear Eq")
    print("9. Determinent")
    print("10. Inverse")
    print("11. Singular value Decomposition")
    print("12. Eigen Value")
    print("13. Search Element")
    print("14. Sum of diff of Upper and Lower Traingular Matrix")
    print("15. Exit")
    opt = int(input("Enter option: "))
    print("")
    
    if(opt == 1):
        print("Addition of two matrices")
        print(a+b)
    elif(opt == 2):
        print("Substraction of two matrices")
        print(a-b)
    elif(opt == 3):
        sclr = int(input("Enter the scalar: "))
        print("After Scalar is multiplied to matrix a")
        print(sclr*a)
    elif(opt == 4):
        print("Dot product of two matrices")
        print(a*b)
    elif(opt == 5):
        print("Matrix mul of two matrices")
        print(a@b)
    elif(opt == 6):
        print("Transpose of matrix a")
        print(np.transpose(a))
    elif(opt == 7):
        print("Trace of matrix a")
        print(np.trace(a))
    elif(opt == 8):
        print("solving system of linear eqns of 2 matrices")
        print(np.linalg.solve(a,b))
    elif(opt == 9):
        print("Determinent of matrix a")
        print(np.linalg.det(a))
    elif(opt == 10):
        print("Inverse of matrix a")
        print(np.linalg.inv(a))
    elif(opt == 11):
        print("Singular value decomposition of matrix a")
        print(np.linalg.svd(a))
    elif(opt == 12):
        print("Eigen values of matrix a")
        print(np.linalg.eig(a))
    elif(opt == 13):
        ele = int(input("Enter the element to b searched in matrix a: "))
        print(np.where(a == ele))
    elif(opt == 14):
        upper=0
        lower=0
        upper1=0
        lower1=0
        for i in range(r):
            for k in range(i+1):
                lower = lower + a[i][k]
        for i in range(r):
            for k in range(c):
                upper = upper + a[i][k]
        upper = upper - lower + np.trace(a)
        print("Upper and Lower traingular matrices sum of a")
        print(upper,lower)
        
        for i in range(r):
            for k in range(i+1):
                lower1 = lower1 + b[i][k]
        for i in range(r):
            for k in range(c):
                upper1 = upper1 + b[i][k]
        upper1 = upper1 - lower1 + np.trace(b)
        print("Upper and Lower traingular matrices sum of b")
        print(upper1,lower1)
        sum = (upper-lower) + (upper1-lower1)
        print("Sum of diff of Upper and Lower Traingular Matrix")
        print(sum)
                
    elif(opt == 15):
        sys.exit()
    else:
        print("Invalid option selected")
        sys.exit()
