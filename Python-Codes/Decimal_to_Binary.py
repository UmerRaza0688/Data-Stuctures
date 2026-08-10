# an application of stack, Decimal to Binary

def dec_to_bin(num):
    # case 1: if num is 0
    if num == 0:
        return '0'
    
    stack = []      # an empty stack

    while num != 0:
        remainder = num % 2     # remainder will always be 0 or 1
        num = num // 2          # decrease the num, dividing by 2
        stack.append(remainder) # push remainder in stack

    ret_str = ''
    while stack:
        ret_str += str(stack.pop())     # pop val from stack and store it in ret var, ofcourse this will be in reverse order 

    return ret_str


if __name__ == '__main__':
    print(dec_to_bin(5))