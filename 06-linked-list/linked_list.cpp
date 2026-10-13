// Singly linked list: insert, delete, search, reverse, count.
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int value;
    Node* next;
    explicit Node(int v) : value(v), next(nullptr) {}
};

class LinkedList {
    Node* head = nullptr;

public:
    LinkedList() = default;
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;
    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertAtHead(int value) {  // O(1)
        Node* node = new Node(value);
        node->next = head;
        head = node;
    }

    void insertAtTail(int value) {  // O(n)
        Node* node = new Node(value);
        if (!head) { head = node; return; }
        Node* current = head;
        while (current->next) current = current->next;
        current->next = node;
    }

    bool remove(int value) {  // O(n)
        if (!head) return false;
        if (head->value == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }
        Node* current = head;
        while (current->next) {
            if (current->next->value == value) {
                Node* temp = current->next;
                current->next = temp->next;
                delete temp;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool search(int value) const {  // O(n)
        for (Node* c = head; c; c = c->next)
            if (c->value == value) return true;
        return false;
    }

    int count() const {  // O(n)
        int total = 0;
        for (Node* c = head; c; c = c->next) total++;
        return total;
    }

    void reverse() {  // O(n) time, O(1) space
        Node *previous = nullptr, *current = head;
        while (current) {
            Node* next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        head = previous;
    }

    vector<int> toVector() const {
        vector<int> result;
        for (Node* c = head; c; c = c->next) result.push_back(c->value);
        return result;
    }
};

int main() {
    LinkedList ll;
    for (int v : {1, 2, 3}) ll.insertAtTail(v);
    ll.insertAtHead(0);
    assert((ll.toVector() == vector<int>{0, 1, 2, 3}));
    assert(ll.count() == 4);
    assert(ll.search(2) && !ll.search(9));
    assert(ll.remove(1) && !ll.remove(42));
    assert((ll.toVector() == vector<int>{0, 2, 3}));
    ll.reverse();
    assert((ll.toVector() == vector<int>{3, 2, 0}));
    cout << "linked_list.cpp: all tests passed\n";
    return 0;
}
