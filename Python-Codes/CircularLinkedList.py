# / Implementing a Circular Linked List or Ring with it's basic operations

# class for single node
class Node:
    def __init__(self, v = None):
        self.val = v
        self.next = None
    
# class for circular linked list which is also called as 'Ring'
class Ring:
    def __init__(self):
        self.head = None

# Operations of list

# to display list 
def __str__(self):
    ret_str = '[ '
    temp = self.head
    while temp is not None:
        ret_str += str(temp.val) + ', '
        temp = temp.next

        if temp == self.head:      # diffirent for Ring (change), get out of loop
            break
    
    ret_str = ret_str.rstrip(', ')
    ret_str += ' ]'
    return ret_str

Ring.__str__ = __str__

# fun to get last node of list, when we need    (change)
def _get_last(self):
    # case 1: if no node
    if self.head == None:
        return None
    
    # case 2: if one node
    # if self.head.next == self.head:
        # return self.head

    # case 3: if more then one nodes, also cover case 2
    temp = self.head
    while temp.next != self.head:
        temp = temp.next
    
    return temp

Ring._get_last = _get_last

# fun to push val at last
def push(self, val):
    new_node = Node(val)

    # case 1: if no node
    if self.head == None:
        self.head = new_node
        new_node.next = self.head
        return
    
    # case 2: if atleast one node
    if self.head.next == self.head:
        self.head.next = new_node
        new_node.next = self.head
        return

    # case 3: if more then one node
    temp = self.head.next
    while temp.next != self.head:
        temp = temp.next
    
    temp.next = new_node
    new_node.next = self.head
    return

# def push(self, val):
#     self.insert(self.len()-1, val)

Ring.push = push

# fun to pop val at last
def pop(self):
    # case 1: if no node 
    if self.head == None:
        raise Exception("No node, list is empty")
    
    # case 2: if one node
    if self.head.next == self.head:
        self.head = None
        return

    # case 3: if more then one nodes
    temp = self.head
    while temp.next != self.head:
        prev = temp
        temp = temp.next

    prev.next = self.head
    temp = None

    return    

Ring.pop = pop

# fun to insert val, at specific index
def insert(self, index, val):
    new_node = Node(val)

    last = self._get_last()     # need last for ring (change)

    # if head is None and index is greater then 0
    if self.head is None and index > 0:
        raise IndexError("Cannot insert at index at " + str(index) + " because list is empty!")

    # case 1: if index is zero
    if index == 0:
        new_node.next = self.head
        self.head = new_node

        # also need to set the last pointer to new head (change)
        if last is None:
            self.head.next = self.head      # if no node before
        else:
            last.next = self.head           # if one node exist

        return
    

    # case 2: if any other index
    temp = self.head
    counter = 0
    while counter < index:
        prev = temp
        temp = temp.next
        counter += 1

        # stop if ring completed
        # if temp == self.head:
            # break

    new_node.next = temp
    prev.next = new_node
    
    return

Ring.insert = insert

# fun to remove a specific val
def remove(self, val):

    temp = self.head
    last = self._get_last()     # (change)

    # case 1: if no node
    if self.head is None:
        raise Exception("No node, can't remove!")

    # case 2: if val matches at first node 
    if self.head.val == val:
        if last == self.head:
            self.head = None    # just one node
        else:
            self.head = self.head.next
            last.next = self.head
        
        return
    
    # case 3: if value match at any other index
    prev = temp
    temp = temp.next

    while temp != last.next:
        if temp.val == val:
            break

        prev = temp
        temp = temp.next
    
    # val not found 
    if temp == last.next:
        return
    
    prev.next = temp.next
    return

Ring.remove = remove

# fun to remove val at specific index
def removeAt(self, index):
    last = self._get_last()
    temp = self.head

    # if list is empty
    if self.head is None:
        raise Exception("list is empty!")

    # if index is zero
    if index == 0:
        if last ==  self.head:
            self.head = None
        else:
            last.next = self.head.next
            self.head = last.next

        return

    # other indices
    counter = 0

    while counter < index:
        prev = temp
        temp = temp.next
        counter += 1

        # return if full loop
        if temp == last.next:
            return    

    # break link
    prev.next = temp.next

Ring.removeAt = removeAt

# fun to get val at specific index
def get(self, index):
    # case1 : if no node
    if self.head == None:
        return None

    # case 2: if one node
    if self.head.next == self.head: 
        return self.head.val
    
    # case 3: others
    temp = self.head
    counter = 0

    while counter < index:
        temp = temp.next
        counter += 1

    return temp.val

Ring.get = get

# fun to know val is in list or not
def find(self, val):
    last = self._get_last()
    
    # case 1: if list is empty
    if self.head is None:
        return None
    
    # case 2: if val found at first node 
    if self.head.val == val:
        return 0    # return index num 
    
    # case 3: if val found at any other index
    temp = self.head.next
    counter = 1
     
    while temp != last.next:
        if temp.val == val:
            return counter

        temp = temp.next
        counter += 1

    if temp == last.next:
        return "not in the list"

Ring.find = find

# fun to get lenght of list
def len(self):
    last = self._get_last()

    # case 1: if no node
    if self.head is None:
        return 0
    
    # case 2: if one node
    if self.head.next == self.head:
        return 1

    # case 3: if more then one node
    temp = self.head.next
    counter = 1

    while temp != last.next:
        temp = temp.next
        counter += 1
    
    return counter

Ring.len = len

# fun to update val at specific index
def update(self, index, val):
    # case 1: if no node
    if self.head == None:
        raise Exception("No node, can't update!")
    
    # case 2: if index is 0
    if index == 0:
        self.head.val = val
        return
    
    # case 3: any other index
    temp = self.head.next
    counter = 1

    while counter < index:
        if temp.val == val:
            break

        temp = temp.next
        counter += 1

    temp.val = val

    return

Ring.update = update

# Josephus problem
def josephus_problem(self, k):
    # if list is empty or k <= 0
    if self.head is None or k <= 0:
        return None
    


    temp = self.head
    prev = None

    # continue until one node left
    while temp.next != temp:

        # if k is 1
        if k == 1:
            prev = temp
            while prev.next != temp: 
                prev = prev.next
        # if k > 1
        else:
            for _ in range(k - 1): # due to 0 index base, k is k-1
                prev = temp
                temp = temp.next

        print(f"Removed: {temp.val}")
        prev.next = temp.next   # break the link, release the kth node

        temp = temp.next        # move temp to next node, after removing kth node

    self.head = temp            # update head
    return temp.val             # return master node

Ring.josephus_problem = josephus_problem