# Implemnting a Queue data structure
class Queue:
    def __init__(self):
        self.size = 5       # size of queue
        self.q = list(range(self.size))     # making list limited size by some mechanism
        self.i = 0
        self.o = 0

        self.is_full = False
        self.is__empty = True

# increement function, to inc i & o
def _inc(self, index):
    # making index of i & o zero, if they equal to size 
    if index + 1 == self.size:
        return 0        
    else:
       return index + 1

Queue._inc = _inc

# enqueue fun, to enter val in queue
def enqueue(self, val):
    if self.is_full:
        raise IndexError("Queue is full, can't enqueue!")
    
    # if not full, then entring val in queue
    self.q[self.i] = val
    self.i = self._inc(self.i)      # change i index

    # if after enqueue a val, i & o became equal mean queue is full
    if self.i == self.o:
        self.is_full = True
    
    self.is_empty = False

Queue.enqueue = enqueue

# dequeue fun
def dequeue(self):
    if self.is_empty:
        raise IndexError("Queue is empty, can't dequeue!")
    
    # if not empty
    ret = self.q[self.o]
    self.o = self._inc(self.o)      # change o index

    # if after dequeue a val, i & o became equal mean queue is empty
    if self.o == self.i:
        self.is_empty = True

    self.is_full = False

    return ret

Queue.dequeue = dequeue

# display queue
def __str__(self):
    return str(self.q) + ' ,  in: ' + str(self.i) + ',  out: ' + str(self.o)

Queue.__str__ = __str__

if __name__ == "__main__":
    q = Queue()

    q.enqueue(1)
    q.enqueue(4)
    q.enqueue(1)
    q.enqueue(4)
    q.enqueue(5)
    # q.enqueue(5)
    print(q)

    q.dequeue()
    q.dequeue()
    q.dequeue()
    q.dequeue()
    q.dequeue()
    # q.dequeue()
    print(q)