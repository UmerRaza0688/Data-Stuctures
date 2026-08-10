# Doubly Circular Linked List implementation
# class for single node
class Node:
    def __init__(self, v = None):
        self.val = v
        self.next = None
        self.prev = None

# class of Doubly connected Ring
class doubly_ring:
    def __init__(self):
        self.head = None
        
# to print ring
def __str__(self):
    ret_str = '[ '
    temp = self.head
    while temp is not None:
        ret_str += str(temp.val) + ', '
        temp = temp.next

        if temp == self.head:           # diffirent for Ring (change), get out of loop
            break

    ret_str = ret_str.rstrip(', ')      
    ret_str += ' ]'
    return ret_str
    
doubly_ring.__str__ = __str__

# to get last node of circular list,   (change)
def _get_last(self):
    # if no node
    if self.head is None:
        return None
    
    # case 2: if one node
    # if self.head.next == self.head:
        # return self.head

    # case 3: if more then one nodes, also cover case 2
    temp = self.head
    while temp.next != self.head:
        temp = temp.next
    
    return temp

doubly_ring._get_last = _get_last

# fun to push val at last
def push(self, val):
    new_node = Node(val)

    # case 1: if no node
    if self.head == None:
        self.head = new_node
        new_node.next = self.head
        new_node.prev = self.head       # (change)
        return
    
    # case 2: if atleast one node
    if self.head.next == self.head:

        self.head.next = new_node
        new_node.next = self.head

        new_node.prev = self.head       # (change)
        self.head.prev = new_node       # (change)
        return

    # case 3: if more then one node
    temp = self.head.next
    while temp.next != self.head:
        temp = temp.next
    
    temp.next = new_node
    new_node.prev = temp                # (change)
    new_node.next = self.head
    self.head.prev = new_node           # (change)
    return

# def push(self, val):
#     self.insert(self.len()-1, val)

doubly_ring.push = push

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
    self.head.prev = prev           # (change)
    temp = None

    return    

doubly_ring.pop = pop

# fun to insert val, at specific index
def insert(self, index, val):
    new_node = Node(val)

    last = self._get_last()

    # if head is None and index is greater then 0
    if self.head is None and index > 0:
        raise IndexError("Cannot insert at index at " + str(index) + " because list is empty!")

    # case 1: if index is zero
    if index == 0:
        new_node.next = self.head
        new_node.prev = last            # (change)

        self.head = new_node

        # also need to set the last pointer to new head (change)
        if last is None:
            self.head.next = self.head      # if no node before
            self.head.prev = self.head
        else:
            last.next = self.head           # if one node exist
            new_node.next.prev = new_node   # old head prev, to new head(new_node)

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
    temp.prev = new_node            # (change)
    prev.next = new_node
    new_node.prev = prev            # (change)
    
    return

doubly_ring.insert = insert

# fun to remove a specific val
def remove(self, val):

    temp = self.head
    last = self._get_last()     

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
            self.head.prev = last       # (change)

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
    temp.next.prev = prev           # (change)
    return

doubly_ring.remove = remove

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
            self.head.prev = last       # (change)

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
    temp.next.prev = prev           # (change)

doubly_ring.removeAt = removeAt

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

doubly_ring.get = get

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

doubly_ring.find = find

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

doubly_ring.len = len

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

doubly_ring.update = update

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
        temp.next.prev = prev   # (change)

        temp = temp.next        # move temp to next node, after removing kth node

    self.head = temp            # update head
    return temp.val             # return master node

doubly_ring.josephus_problem = josephus_problem