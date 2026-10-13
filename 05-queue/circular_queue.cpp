// Circular queue (FIFO) with a fixed-size array.
#include <cassert>
#include <iostream>
#include <stdexcept>
using namespace std;

class CircularQueue {
    int* data;
    int capacity, front, count;

public:
    explicit CircularQueue(int cap) : capacity(cap), front(0), count(0) { data = new int[cap]; }
    ~CircularQueue() { delete[] data; }
    CircularQueue(const CircularQueue&) = delete;
    CircularQueue& operator=(const CircularQueue&) = delete;

    bool isEmpty() const { return count == 0; }
    bool isFull() const { return count == capacity; }
    int size() const { return count; }

    void enqueue(int value) {  // O(1)
        if (isFull()) throw overflow_error("queue is full");
        data[(front + count) % capacity] = value;
        count++;
    }
    int dequeue() {  // O(1)
        if (isEmpty()) throw underflow_error("queue is empty");
        int value = data[front];
        front = (front + 1) % capacity;
        count--;
        return value;
    }
    int peek() const {
        if (isEmpty()) throw underflow_error("queue is empty");
        return data[front];
    }
};

int main() {
    CircularQueue q(3);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    assert(q.isFull());
    assert(q.dequeue() == 1);
    q.enqueue(4);  // wraps around
    assert(q.dequeue() == 2);
    assert(q.dequeue() == 3);
    assert(q.dequeue() == 4);
    assert(q.isEmpty());
    cout << "circular_queue.cpp: all tests passed\n";
    return 0;
}
