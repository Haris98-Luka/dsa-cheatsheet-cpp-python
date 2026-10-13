# Linked List (Singly)

Each node stores a value and a pointer to the next node. Memory is not contiguous.

| Operation | Time |
|-----------|------|
| Insert at head | O(1) |
| Insert at tail | O(n) (O(1) if you keep a tail pointer) |
| Delete by value | O(n) |
| Search | O(n) |
| Access by index | O(n) |

## Array vs Linked List
| | Array | Linked List |
|---|---|---|
| Access by index | O(1) | O(n) |
| Insert/delete at start | O(n) | O(1) |
| Memory | Contiguous | Scattered, extra pointer per node |

## Practice problems
- Reverse a linked list (included here)
- Detect a cycle (Floyd's tortoise and hare)
- Find the middle node
- Merge two sorted lists

## Files
- [`linked_list.py`](linked_list.py)
- [`linked_list.cpp`](linked_list.cpp)
