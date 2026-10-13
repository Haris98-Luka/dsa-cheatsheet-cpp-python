# Arrays

An array stores elements in contiguous memory, so reading by index is instant.

| Operation | Time | Why |
|-----------|------|-----|
| Access by index | O(1) | Direct memory address |
| Search (unsorted) | O(n) | May check every element |
| Insert at index | O(n) | Elements shift right |
| Delete at index | O(n) | Elements shift left |
| Append at end | O(1) amortized | No shifting needed |

**Space:** O(n)

## When to use
- You need fast access by index.
- The size is known or changes rarely.

## Common interview patterns
- Two pointers (reverse, pair sum in sorted array)
- Sliding window (max sum of k elements)
- Prefix sums (range queries)

## Files
- [`arrays.py`](arrays.py) – Python
- [`arrays.cpp`](arrays.cpp) – C++
