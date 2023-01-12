'''
Queue using Linked List
CS20B1107, SRIRAM REDDY CHEERLA
'''
import sys
class Node(object):
    def __init__(self,x):
        self.data = x
        self.nextNode = None

class Queue(object):
    def __init__(self):
        self.hNode = None

    def enqueue(self, x):
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

    def dequeue(self):
        if(self.hNode is None):
            print("The queue is Empty")
            return
        self.hNode = self.hNode.nextNode;
        
    def peek(self):
        if(self.hNode is None):
            print("The queue is Empty")
            return
        print("The element at front of the queue is")
        print(self.hNode.data)

    def print(self):
        if(self.hNode is None):
            print("The queue is Empty")
            return
        print("The elements in the queue are")
        tNode=self.hNode
        print(tNode.data)
        while(tNode.nextNode is not None):
            tNode = tNode.nextNode
            print(tNode.data)
    def Exit(self):
        sys.exit()

            
queue1 = Queue()

while(1):
    print("1. Enqueue")
    print("2. Dequeue")
    print("3. Peek")
    print("4. Print")
    print("5. Exit")
    opt = int(input("Enter option: "))
    
    if(opt == 1):
        ele = int(input("Enter the element to Enqueue into stack "))
        queue1.enqueue(ele)
    elif(opt == 2):
        queue1.dequeue()
    elif(opt == 3):
        queue1.peek()
    elif(opt == 4):
        queue1.print()
    elif(opt == 5):
        queue1.Exit()
    else:
        print("Invalid option selected")
        sys.exit()
