# implementing stack by python built in lists
# stack class 
class Stack:
    def __init__(self):
        self.__l = []           # double underscore before 'l' is for not can accessible outside the class

    # display stack
    def __str__(self):
        ret_str = '[ '
        for i in self.__l:
            ret_str +=  str(i) + ' : '

        ret_str = ret_str.rstrip(': ')
        ret_str += ' ]'

        return ret_str

    # push fun
    def push(self, val):
        self.__l.append(val)

    # pop fun
    def pop(self):
        self.__l.pop()

    # peek fun
    def peek(self):
        return self.__l[-1]       # as python lists provide us negative indexing that's why -1 index will return last val of stack
    

if __name__ == "__main__":
    stack = Stack()

    stack.push(1)
    stack.push(2)
    stack.push(3)
    stack.push(4)
    print(stack)

    print(f"Last val: {stack.peek()}")

    stack.pop()
    stack.pop()
    print(stack)
    print(f"Last val: {stack.peek()}")