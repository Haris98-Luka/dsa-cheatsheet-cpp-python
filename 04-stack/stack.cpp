// Stack (LIFO) using a fixed-size array, plus balanced brackets.
#include <cassert>
#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>
using namespace std;

class ArrayStack {
    int* data;
    int top;
    int capacity;

public:
    explicit ArrayStack(int cap = 100) : top(-1), capacity(cap) { data = new int[cap]; }
    ~ArrayStack() { delete[] data; }
    ArrayStack(const ArrayStack&) = delete;
    ArrayStack& operator=(const ArrayStack&) = delete;

    bool isEmpty() const { return top == -1; }
    bool isFull() const { return top == capacity - 1; }
    int size() const { return top + 1; }

    void push(int value) {  // O(1)
        if (isFull()) throw overflow_error("stack overflow");
        data[++top] = value;
    }
    int pop() {  // O(1)
        if (isEmpty()) throw underflow_error("stack underflow");
        return data[top--];
    }
    int peek() const {  // O(1)
        if (isEmpty()) throw underflow_error("stack is empty");
        return data[top];
    }
};

// O(n)
bool isBalanced(const string& text) {
    stack<char> st;
    for (char ch : text) {
        if (ch == '(' || ch == '[' || ch == '{') {
            st.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (st.empty()) return false;
            char open = st.top();
            st.pop();
            if ((ch == ')' && open != '(') || (ch == ']' && open != '[') ||
                (ch == '}' && open != '{'))
                return false;
        }
    }
    return st.empty();
}

int main() {
    ArrayStack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    assert(s.peek() == 3);
    assert(s.pop() == 3);
    assert(s.size() == 2);
    assert(isBalanced("{[()]}"));
    assert(!isBalanced("{[(])}"));
    assert(!isBalanced("(("));
    cout << "stack.cpp: all tests passed\n";
    return 0;
}
