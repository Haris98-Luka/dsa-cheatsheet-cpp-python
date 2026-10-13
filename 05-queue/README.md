# Queue

**FIFO** – First In, First Out. Think of a line at a ticket counter.

| Operation | Time |
|-----------|------|
| enqueue | O(1) |
| dequeue | O(1) |
| peek | O(1) |

## Why circular?
A plain array queue wastes space at the front after dequeues. A circular queue wraps the indexes with `% capacity` and reuses that space.

## Real uses
- Task scheduling and print queues
- BFS (breadth-first search) in graphs
- Buffering data streams

## Files
- [`circular_queue.py`](circular_queue.py)
- [`circular_queue.cpp`](circular_queue.cpp)
