# Implementing a list, with it's operations
# class for single node of list, a node consist of two things(data in it & address of next node)
class Node:
    def __init__(self, val = None):
        self.val = val    # data of node
        self.next = None    # address of next node, initialy it's None

# class of LinkedList
class LinkedList:
    def __init__(self):
        self.head = None    # head of LinkedList, if no nodes head will be None/Null

# function to printin a list, simply called when print(list)
def __str__(self):
    ret_str = '[ '
    temp = self.head
    while temp is not None:
        ret_str += str(temp.val) + ', '
        temp = temp.next

    ret_str = ret_str.rstrip(', ')
    ret_str += ' ]'
    return ret_str

LinkedList.__str__ = __str__    #After implementing function we add it to linked list 
    
#Function to push a value in list
# def push(self, val):
#     new_node = Node(val)

#     #first case, if no node currently
#     if self.head is None:
#         self.head = new_node
#         return
    
#     #2nd case, for all other exceptions
#     last = self.head
#     while last.next is not None:
#         last = last.next        #until we reach last node

#     last.next = new_node        # attach new_node to end
def push(self, val):
    self.insert(self.len(), val) 

LinkedList.push = push

#Function to push a value in list
def pop(self):
    # if no node
    if self.head is None:
        raise Exception("cannot pop, no value!")

    # if single node
    if self.head.next is None:
        val = self.head.val     # value which is to be pop
        self.head = None
        return val
     
    # for all other cases
    temp = self.head
    while temp.next is not None:
        prev = temp
        temp = temp.next

    val = temp.val
    prev.next = None    # after function is end, due to local scope temp will also be removed
    return val
LinkedList.pop = pop

#Function to insert a value in list at particular index
def insert(self, index, val):
    new_node = Node(val)

    # if index is zero
    if index == 0:
        new_node.next = self.head
        self.head = new_node
        return
    
    # for mid & last index, a single efficent code block
    temp = self.head

    counter = 0
    while temp is not None and counter < index:
        prev = temp
        temp = temp.next
        counter += 1
    
    prev.next = new_node
    new_node.next = temp

LinkedList.insert = insert

#Function to remove a value in list at particular index
def remove(self, val):

    temp = self.head

    #1st case, if no value
    if self.head is None:
        raise Exception('cannot remove, no value')
    
    #2nd case, if value at first index
    if temp is not None:
        if temp.val == val:
            self.head = temp.next
            temp = None             #actually not needed
            return
        
    #all other cases
    while temp is not None:
        if temp.val == val:
            break
        
        prev = temp             #hold temp last state in prev
        temp = temp.next
    
    if temp is None:
        return                  #Value not found in list
    
    # skip the node 'temp'
    prev.next = temp.next       # just loose the refrence to delete the item

LinkedList.remove = remove

# find the length of list
def len(self):
    temp = self.head

    #if no values
    if self.head is None:
        return 0
    
    counter = 0
    #if list has values
    while temp is not None:
        temp = temp.next
        counter += 1

    return counter

LinkedList.len = len


# get the value from given index
def get(self, index):
    # case 1, if no nodes
    if self.head is None:
        raise Exception("list is empty!")
    
    # case 2, if index is 0
    if index == 0:
        return self.head.val
    
    # case 3, if index is > 0
    temp = self.head
    counter = 0
    while temp is not None and counter < index: 
        temp = temp.next
        counter += 1
    
    return temp.val

LinkedList.get = get

# to update a val at specific index
def update(self, index, val):
        # case 1: if no node
    if self.head is None:
        raise Exception("can't remove, no value!")
    
    # if index is 0
    if index == 0:
        self.head.val = val
        return

    # if any other index
    temp = self.head
    counter = 0
    while temp is not None and counter < index:
        temp = temp.next
        counter += 1
    
    temp.val = val
    return

LinkedList.update = update

# get Most common value from list


# Main fun ):-
if __name__ == "__main__":
    l = LinkedList()
    l.push(82)                  #push case 1
    l.push(80)                  #push case 2
    l.push(88)                  #push case 2
    l.push(80)                  #push case 2
    l.push(87)