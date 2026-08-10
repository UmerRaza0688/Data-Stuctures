# Implementing a Doubly Linked List with it's basic operations
# Whereever the 'change' is commented, means there is change else is same like SinglyLinkedList 

# class for sigle node
class Node:
    def __init__(self, v = None):
        self.val = v
        self.next = None
        self.prev = None    # changing, we also want to secure address of previues node

# class for DoublyLinkedList
class Doubly:
    def __init__(self):
        self.head = None

# Operations, that will perform by DoublyLinkedList
# All the functions will be added to 'Doubly' class at run time

# Method to print List
def __str__(self):
    ret_str = '[ '
    temp = self.head
    while temp is not None:
        ret_str += str(temp.val) + ', '
        temp = temp.next

    ret_str = ret_str.rstrip(', ')
    ret_str += ' ]'
    return ret_str

Doubly.__str__ = __str__

# Methode to Push a value in list
# def push(self, val):
#     new_node = Node(val)

#     # case 1: if no Node before
#     if self.head is None:
#         self.head = new_node
#         return
    
#     # case 2: any other case
#     last = self.head
#     while last.next is not None:
#         last = last.next

#     last.next = new_node
#     new_node.prev = last        # change, we preserv last node also
#     return
# 
def push(self, val):
    self.insert(self.len(), val) 

Doubly.push = push

# Methode to pop a val from list
def pop(self):
    # case 1: if no node
    if self.head is None:
        raise Exception("can't pop, no value!")
    
    # case 2: if only one node exist
    if self.head.next is None:
        val = self.head.val
        self.head = None
        return val
    
    # case 3: if any other case
    temp = self.head
    while temp.next is not None:
        prev = temp
        temp = temp.next

    val = temp.val

    prev.next = None
    temp.prev = None        # changing

    return val

Doubly.pop = pop

# Insert a val in list 
def insert(self, index, val):
    new_node = Node(val)

    # case 1: if index is 0
    if index == 0:
        new_node.next = self.head
        
        if self.head is not None:           #change
            self.head.prev = new_node
    
        self.head = new_node
        return

    # case 2: other indecies
    counter = 0
    temp = self.head
    while temp is not None and counter < index:
        prev = temp
        temp = temp.next
        counter += 1
    
    prev.next = new_node
    new_node.prev = prev    # change


    new_node.next = temp
    if temp is not None:
        temp.prev = new_node    # change
    
Doubly.insert = insert

def remove(self, val):
    # case 1: if no node
    if self.head is None:
        raise Exception("can't remove, no value!")
    
    # case 2: if val find at first index
    if self.head.val == val:
        self.head = self.head.next
        
        if self.head.next is not None:
            self.head.prev = None

        return

    # case 3: if val at any other index
    temp = self.head
    while temp is not None:
        # if val find before list end
        if temp.val == val:
            break

        prev = temp
        temp = temp.next

    if temp is None:
        print("Value not found in the list!")
        return

    prev.next = temp.next
    if temp.next is not None:       # change
        temp.next.prev = prev
    
    return

Doubly.remove = remove

# length methd, to the list length
def len(self):
    temp = self.head

    #if no values
    if self.head is None:
        return 0
    
    #if list has values
    counter = 0
    while temp is not None:
        temp = temp.next
        counter += 1

    return counter

Doubly.len = len

# get a val at specific index
def get(self, index):
    # case 1: if no node
    if self.head is None:
        raise Exception("can't remove, no value!")
    
    # case 2: if index is 0
    if index == 0:
        return self.head.val
    
    # case 3: if any other index
    temp = self.head
    counter = 0
    while temp is not None and counter < index:
        temp = temp.next
        counter += 1

    return temp.val


Doubly.get = get

# to update a val at specific index
def update(self, index, val):
    # case 1: if no node
    if self.head is None:
        raise Exception("can't update, no value!")
    
    # case 2: if index is 0
    if index == 0:
        self.head.val = val
        return

    # case 3: if any other index
    temp = self.head
    counter = 0
    while temp is not None and counter < index:
        temp = temp.next
        counter += 1
    
    temp.val = val
    return


Doubly.update = update

# Testing List
if __name__ == "__main__":
    l = Doubly()

    # push a val
    l.push(2)
    l.push(3)
    print(l)

    # pop a val
    l.pop()
    l.pop()
    # l.pop()
    # l.remove(4)
    print(l)

    # insert a val
    l.insert(0, 80)
    l.insert(0, 90)
    l.insert(1, 100)
    l.insert(3, 68)
    l.push(80)
    print(l)

    # remove a val
    l.remove(90)
    l.remove(80)
    l.remove(80)
    # l.remove(8)
    print(l)

    # length methd, to the list length
    print(f"Length of list: {l.len()}")

    # get a val at specific index
    print(f"Value at index 0: {l.get(0)}")
    print(f"Value at index 0: {l.get(1)}")

    l.push(99)
    # update value
    print(l)
    l.update(0, 80)
    print(l)
    l.update(2, 80)
    print(l)