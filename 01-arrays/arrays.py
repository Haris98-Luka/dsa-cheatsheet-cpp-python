"""Array basics: traverse, insert, delete, reverse, rotate, min/max."""


def insert_at(arr, index, value):
    """Insert value at index. O(n) because elements shift right."""
    arr.insert(index, value)
    return arr


def delete_at(arr, index):
    """Delete element at index. O(n) because elements shift left."""
    arr.pop(index)
    return arr


def reverse(arr):
    """Reverse in place using two pointers. O(n) time, O(1) space."""
    left, right = 0, len(arr) - 1
    while left < right:
        arr[left], arr[right] = arr[right], arr[left]
        left += 1
        right -= 1
    return arr


def rotate_left(arr, k):
    """Rotate left by k positions. O(n)."""
    if not arr:
        return arr
    k %= len(arr)
    return arr[k:] + arr[:k]


def find_min_max(arr):
    """Return (min, max) in a single pass. O(n)."""
    smallest = largest = arr[0]
    for x in arr[1:]:
        smallest = min(smallest, x)
        largest = max(largest, x)
    return smallest, largest


if __name__ == "__main__":
    data = [10, 20, 30, 40, 50]
    assert insert_at(data[:], 2, 99) == [10, 20, 99, 30, 40, 50]
    assert delete_at(data[:], 1) == [10, 30, 40, 50]
    assert reverse(data[:]) == [50, 40, 30, 20, 10]
    assert rotate_left(data, 2) == [30, 40, 50, 10, 20]
    assert find_min_max(data) == (10, 50)
    print("arrays.py: all tests passed")
