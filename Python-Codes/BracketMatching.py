# an application of stack, Bracket matching
# {([])()},     True
# ({)[]),       False
# [({}),        False

def is_matching(string):
    # with the help o zip we make a dictonary with key(opening) & values(closing)
    opening = '({['
    closing = ')}]'
    mapping = dict(zip(opening, closing))       # mapping is dict
    # print(mapping)

    stack = []

    # Traverse through string for every single character
    for c in string:

        # There will be three cases
        # case 1: if char in string is not a bracket
        if c not in mapping.keys() and c not in mapping.values():
            continue        # we don't any concern with any other char except brackets, so ignore them

        # case 2: if brackets found
        if c in mapping:     # if opening bracket found, it's crrossponding closing bracket will be push to stack
            stack.append(mapping[c])    # mapping[c] gives us crrossponding closing bracket

        # case 3: specialy for last char in stack
        # this will cover two states of stack, 1: if stack is empty(no closing bracket) 2: if bracket is mismatched
        # for both, if one of the state is true, we will return false, because brackets are unmatched
        elif len(stack) == 0 or c != stack.pop():
            return False
        
    
    # At last, if the len(stack) == 0, then string has no problem but after loop if len > 0 then 
    # there is a problem with string, in this case we will also return false else if len == 0, return true
    return len(stack) == 0

if __name__ == "__main__":
    # string = '[{()}]'
    # string = '2 + (3 * 5) *  ((2 * 2) - 5)'
    # string = '2 + (3 * 5) *  ((2 * 2) - 5))'
    string = '[2 + (3 * 5) *  ((2 * 2) - 5)'
    print(is_matching(string))