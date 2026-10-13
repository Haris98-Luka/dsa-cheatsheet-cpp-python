"""Circular queue (FIFO) with a fixed-size array."""


class CircularQueue:
    def __init__(self, capacity):
        self._data = [None] * capacity
        self._capacity = capacity
        self._front = 0
        self._size = 0

    def enqueue(self, value):  # O(1)
        if self.is_full():
            raise OverflowError("queue is full")
        rear = (self._front + self._size) % self._capacity
        self._data[rear] = value
        self._size += 1

    def dequeue(self):  # O(1)
        if self.is_empty():
            raise IndexError("queue is empty")
        value = self._data[self._front]
        self._front = (self._front + 1) % self._capacity
        self._size -= 1
        return value

    def peek(self):
        if self.is_empty():
            raise IndexError("queue is empty")
        return self._data[self._front]

    def is_empty(self):
        return self._size == 0

    def is_full(self):
        return self._size == self._capacity

    def size(self):
        return self._size


if __name__ == "__main__":
    q = CircularQueue(3)
    q.enqueue(1)
    q.enqueue(2)
    q.enqueue(3)
    assert q.is_full()
    assert q.dequeue() == 1
    q.enqueue(4)  # wraps around
    assert q.dequeue() == 2
    assert q.dequeue() == 3
    assert q.dequeue() == 4
    assert q.is_empty()
    print("circular_queue.py: all tests passed")
