# implementing Stack by Linked list

# list single node
class Node:
    def __init__(self, v = None):
        self.val = v
        self.next = None

# stack class
class Stack:
    def __init__(self):
        self.top = None

    # display stack
    def __str__(self):
        ret_str = '[ '
        temp = self.top

        while temp is not None:
            ret_str += str(temp.val) + ' -> '
            temp = temp.next

        ret_str = ret_str.rstrip('-> ')
        ret_str += ' ]'
        return ret_str

    # push in stack()
    def push(self, val):
        new_node = Node(val)

        new_node.next = self.top
        self.top = new_node

    # pop from stack
    def pop(self):
        self.top = self.top.next

    # peek in stack
    def peek(self):
        return self.top.val