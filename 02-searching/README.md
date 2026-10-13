# Searching

| Algorithm | Best | Average | Worst | Needs sorted data? |
|-----------|------|---------|-------|--------------------|
| Linear search | O(1) | O(n) | O(n) | No |
| Binary search | O(1) | O(log n) | O(log n) | **Yes** |

**Space:** O(1) for both (iterative versions).

## Binary search idea
Look at the middle element. If it is too small, discard the left half. If too big, discard the right half. Repeat.

## Common mistakes
- Using binary search on unsorted data.
- `mid = (low + high) / 2` can overflow in C++. Use `low + (high - low) / 2`.
- Wrong loop condition: use `low <= high`.

## Files
- [`searching.py`](searching.py)
- [`searching.cpp`](searching.cpp)
