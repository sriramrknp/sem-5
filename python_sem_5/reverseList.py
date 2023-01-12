class Node(object):
    def __init__(self, value1):
        self.value = value1
        self.next = None
    
def create(x):
    newNode = Node(x)
    if(root == None):
        root = newNode
        newNode.nextNode = root
    else:
        tNode = root
        while(tNode.nextNode is not None):
            tNode = tNode.nextNode
        temp = tNode.nextNode 
        tNode.nextNode = newNode  
        newNode.nextNode = temp

# def reverse(root):
num=0
root = None
while(1):
    num = int(input())
    create(num)
