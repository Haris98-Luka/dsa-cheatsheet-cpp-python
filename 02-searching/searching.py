"""Linear search and binary search."""


def linear_search(arr, target):
    """Return index of target or -1. O(n)."""
    for i, value in enumerate(arr):
        if value == target:
            return i
    return -1


def binary_search(arr, target):
    """Return index of target in a SORTED list or -1. O(log n)."""
    low, high = 0, len(arr) - 1
    while low <= high:
        mid = low + (high - low) // 2
        if arr[mid] == target:
            return mid
        if arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return -1


if __name__ == "__main__":
    unsorted = [7, 3, 9, 1, 5]
    ordered = [1, 3, 5, 7, 9, 11]
    assert linear_search(unsorted, 9) == 2
    assert linear_search(unsorted, 4) == -1
    assert binary_search(ordered, 7) == 3
    assert binary_search(ordered, 1) == 0
    assert binary_search(ordered, 4) == -1
    print("searching.py: all tests passed")
