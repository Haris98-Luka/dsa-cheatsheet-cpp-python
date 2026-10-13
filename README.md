# DSA Cheat Sheet: C++ and Python

Short explanations, complexity tables, and clean, tested code for core Data Structures and Algorithms. Every topic has the **same solution in C++ and Python**, so you can compare them side by side.

Good for interview prep, university exams, and quick revision.

## Topics

| # | Topic | What's inside | Code |
|---|-------|---------------|------|
| 1 | [Arrays](01-arrays) | Insert, delete, reverse, rotate, min/max | [Py](01-arrays/arrays.py) · [C++](01-arrays/arrays.cpp) |
| 2 | [Searching](02-searching) | Linear search, binary search | [Py](02-searching/searching.py) · [C++](02-searching/searching.cpp) |
| 3 | [Sorting](03-sorting) | Bubble, selection, insertion, merge, quick | [Py](03-sorting/sorting.py) · [C++](03-sorting/sorting.cpp) |
| 4 | [Stack](04-stack) | Stack class, balanced brackets | [Py](04-stack/stack.py) · [C++](04-stack/stack.cpp) |
| 5 | [Queue](05-queue) | Circular queue | [Py](05-queue/circular_queue.py) · [C++](05-queue/circular_queue.cpp) |
| 6 | [Linked List](06-linked-list) | Insert, delete, search, reverse | [Py](06-linked-list/linked_list.py) · [C++](06-linked-list/linked_list.cpp) |

## Big-O quick reference

| Structure | Access | Search | Insert | Delete |
|-----------|--------|--------|--------|--------|
| Array | O(1) | O(n) | O(n) | O(n) |
| Linked list | O(n) | O(n) | O(1) at head | O(n) |
| Stack | O(n) | O(n) | O(1) | O(1) |
| Queue | O(n) | O(n) | O(1) | O(1) |

| Sort | Average | Worst | Stable |
|------|---------|-------|--------|
| Bubble / Selection / Insertion | O(n²) | O(n²) | Bubble, Insertion |
| Merge | O(n log n) | O(n log n) | Yes |
| Quick | O(n log n) | O(n²) | No |

## How to run

Each file runs its own tests (`assert`) and prints a success message.

**Python (3.8+):**
```bash
python 03-sorting/sorting.py
```

**C++ (C++17):**
```bash
g++ -std=c++17 03-sorting/sorting.cpp -o sorting
./sorting
```

**Run everything:**
```bash
bash run_all.sh
```

## Roadmap

- [x] Arrays, searching, sorting
- [x] Stack, queue, linked list
- [ ] Doubly and circular linked lists
- [ ] Hash tables
- [ ] Binary trees and BST
- [ ] Heaps and priority queues
- [ ] Graphs (BFS, DFS)
- [ ] Recursion and dynamic programming basics

## Contributing

Contributions are welcome. See [CONTRIBUTING.md](CONTRIBUTING.md). If this repo helped you, please give it a ⭐

## License

[MIT](LICENSE)
