"""Stack (LIFO) implemented with a Python list, plus balanced brackets."""


class Stack:
    def __init__(self):
        self._items = []

    def push(self, value):  # O(1)
        self._items.append(value)

    def pop(self):  # O(1)
        if self.is_empty():
            raise IndexError("pop from empty stack")
        return self._items.pop()

    def peek(self):  # O(1)
        if self.is_empty():
            raise IndexError("peek from empty stack")
        return self._items[-1]

    def is_empty(self):
        return not self._items

    def size(self):
        return len(self._items)


def is_balanced(text):
    """Classic interview problem: are (), [], {} balanced? O(n)."""
    pairs = {")": "(", "]": "[", "}": "{"}
    stack = Stack()
    for ch in text:
        if ch in "([{":
            stack.push(ch)
        elif ch in pairs:
            if stack.is_empty() or stack.pop() != pairs[ch]:
                return False
    return stack.is_empty()


if __name__ == "__main__":
    s = Stack()
    s.push(1)
    s.push(2)
    s.push(3)
    assert s.peek() == 3
    assert s.pop() == 3
    assert s.size() == 2
    assert is_balanced("{[()]}")
    assert not is_balanced("{[(])}")
    assert not is_balanced("((")
    print("stack.py: all tests passed")
