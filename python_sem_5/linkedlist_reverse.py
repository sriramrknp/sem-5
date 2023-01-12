# Global head pointer
root = None

# Node class
class Node(object):
    def __init__(self, value1):
        self.value = value1
        self.next = None

# Create linked list
def create(x):
    global root
    newNode = Node(x)
    if (root == None):
        newNode.next = root
        root = newNode
    else:
        tNode = root
        while (tNode.next is not None):
            tNode = tNode.next
        temp = tNode.next
        tNode.next = newNode
        newNode.next = temp

# To display List
def display():
    global root
    tempNode = root
    while (tempNode.next is not None):
        print(tempNode.value, end=",")
        tempNode = tempNode.next
    print(tempNode.value)


# method to reverse
def reverse(root):
    tempNode = root
    tempNode2 = root.next
    tempNode3 = None
    while(tempNode.next is not None):
        tempNode.next = tempNode3
        tempNode3 = tempNode
        tempNode = tempNode2
        tempNode2 = tempNode2.next
    tempNode.next = tempNode3
    tempNode3 = tempNode
    tempNode = tempNode2
    root = tempNode3
    return root

# Taking stream of inputs
li = []
#li = [int(item) for item in input().split()]
input_string = input()

user_list = input_string.split()

# convert each item to int type
for i in range(len(user_list)):
    user_list[i] = int(user_list[i])

# Creating List
for i in user_list:
#    num = int(i)
    create(i)

# Calling function of list
root = reverse(root)

# Display of list after reversing
display()
