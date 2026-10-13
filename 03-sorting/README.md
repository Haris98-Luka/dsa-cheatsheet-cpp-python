# Sorting

| Algorithm | Best | Average | Worst | Space | Stable |
|-----------|------|---------|-------|-------|--------|
| Bubble | O(n) | O(n²) | O(n²) | O(1) | Yes |
| Selection | O(n²) | O(n²) | O(n²) | O(1) | No |
| Insertion | O(n) | O(n²) | O(n²) | O(1) | Yes |
| Merge | O(n log n) | O(n log n) | O(n log n) | O(n) | Yes |
| Quick | O(n log n) | O(n log n) | O(n²) | O(log n) | No |

## Which one to pick?
- **Small or nearly sorted data:** insertion sort.
- **Guaranteed O(n log n) and stability:** merge sort.
- **Fast in practice, in place:** quick sort.
- **Real projects:** use the built-in `sorted()` (Python) or `std::sort` (C++).

*Stable* means equal elements keep their original order.

## Files
- [`sorting.py`](sorting.py)
- [`sorting.cpp`](sorting.cpp)
