'''
Stack using Linked List
CS20B1107, SRIRAM REDDY CHEERLA
'''
import sys
class Node(object):
    def __init__(self,x):
        self.data = x
        self.nextNode = None

class Stack(object):
    def __init__(self):
        self.hNode = None

    def push(self, x):
        newNode = Node(x)
        if(self.hNode is None):
            newNode.nextNode = self.hNode
            self.hNode = newNode
        else:
            tNode=self.hNode
            while(tNode.nextNode is not None):
                tNode = tNode.nextNode
            temp = tNode.nextNode 
            tNode.nextNode = newNode  
            newNode.nextNode = temp

    def pop(self):
        if(self.hNode is None):
            print("The stack is Empty")
            return
        count=1
        tNode = self.hNode
        if(tNode.nextNode is None):
            self.hNode = None
            return
        while(tNode.nextNode is not None):
            count = count + 1
            tNode = tNode.nextNode
        teNode = self.hNode
        count2 = count
        while((teNode.nextNode is not None) and count2 > 2):
            count2 = count2 - 1
            teNode = teNode.nextNode
        teNode.nextNode = None

    def peek(self):
        if(self.hNode is None):
            print("The stack is Empty")
            return
        tNode=self.hNode
        while(tNode.nextNode is not None):
            tNode = tNode.nextNode
            print("The element at top of the stack is")
        print(tNode.data)

    def print(self):
        if(self.hNode is None):
            print("The stack is Empty")
            return
        print("The elements in the stack are: ")
        tNode=self.hNode
        print(tNode.data)
        while(tNode.nextNode is not None):
            tNode = tNode.nextNode
            print(tNode.data)
    def Exit(self):
        sys.exit()

            
stack1 = Stack()

while(1):
    print("1. Push")
    print("2. Pop")
    print("3. Peek")
    print("4. Print")
    print("5. Exit")
    opt = int(input("Enter option: "))
    
    if(opt == 1):
        ele = int(input("Enter the element to push into stack "))
        stack1.push(ele)
    elif(opt == 2):
        stack1.pop()
    elif(opt == 3):
        stack1.peek()
    elif(opt == 4):
        stack1.print()
    elif(opt == 5):
        stack1.Exit()
    else:
        print("Invalid option selected")
        sys.exit()
