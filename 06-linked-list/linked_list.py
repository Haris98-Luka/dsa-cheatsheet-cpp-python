"""Singly linked list: insert, delete, search, reverse, count."""


class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def insert_at_head(self, value):  # O(1)
        node = Node(value)
        node.next = self.head
        self.head = node

    def insert_at_tail(self, value):  # O(n)
        node = Node(value)
        if self.head is None:
            self.head = node
            return
        current = self.head
        while current.next:
            current = current.next
        current.next = node

    def delete(self, value):  # O(n)
        """Delete first node with this value. Return True if deleted."""
        if self.head is None:
            return False
        if self.head.value == value:
            self.head = self.head.next
            return True
        current = self.head
        while current.next:
            if current.next.value == value:
                current.next = current.next.next
                return True
            current = current.next
        return False

    def search(self, value):  # O(n)
        current = self.head
        while current:
            if current.value == value:
                return True
            current = current.next
        return False

    def count(self):  # O(n)
        total, current = 0, self.head
        while current:
            total += 1
            current = current.next
        return total

    def reverse(self):  # O(n) time, O(1) space
        previous, current = None, self.head
        while current:
            current.next, previous, current = previous, current, current.next
        self.head = previous

    def to_list(self):
        result, current = [], self.head
        while current:
            result.append(current.value)
            current = current.next
        return result


if __name__ == "__main__":
    ll = LinkedList()
    for v in (1, 2, 3):
        ll.insert_at_tail(v)
    ll.insert_at_head(0)
    assert ll.to_list() == [0, 1, 2, 3]
    assert ll.count() == 4
    assert ll.search(2) and not ll.search(9)
    assert ll.delete(1) and not ll.delete(42)
    assert ll.to_list() == [0, 2, 3]
    ll.reverse()
    assert ll.to_list() == [3, 2, 0]
    print("linked_list.py: all tests passed")
