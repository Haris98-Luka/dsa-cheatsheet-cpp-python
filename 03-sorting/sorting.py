"""Bubble, selection, insertion, merge and quick sort."""


def bubble_sort(arr):
    """O(n^2). Stops early if already sorted (best case O(n))."""
    arr = arr[:]
    n = len(arr)
    for i in range(n - 1):
        swapped = False
        for j in range(n - 1 - i):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        if not swapped:
            break
    return arr


def selection_sort(arr):
    """O(n^2). Always does the same number of comparisons."""
    arr = arr[:]
    for i in range(len(arr) - 1):
        smallest = i
        for j in range(i + 1, len(arr)):
            if arr[j] < arr[smallest]:
                smallest = j
        arr[i], arr[smallest] = arr[smallest], arr[i]
    return arr


def insertion_sort(arr):
    """O(n^2) worst, O(n) best. Great for small or nearly sorted data."""
    arr = arr[:]
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr


def merge_sort(arr):
    """O(n log n) always. Stable. Uses O(n) extra space."""
    if len(arr) <= 1:
        return arr[:]
    mid = len(arr) // 2
    left, right = merge_sort(arr[:mid]), merge_sort(arr[mid:])
    merged, i, j = [], 0, 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            merged.append(left[i])
            i += 1
        else:
            merged.append(right[j])
            j += 1
    merged.extend(left[i:])
    merged.extend(right[j:])
    return merged


def quick_sort(arr):
    """O(n log n) average, O(n^2) worst. Not stable."""
    if len(arr) <= 1:
        return arr[:]
    pivot = arr[len(arr) // 2]
    less = [x for x in arr if x < pivot]
    equal = [x for x in arr if x == pivot]
    greater = [x for x in arr if x > pivot]
    return quick_sort(less) + equal + quick_sort(greater)


if __name__ == "__main__":
    data = [64, 25, 12, 22, 11, 25, 90, -3, 0]
    expected = sorted(data)
    for func in (bubble_sort, selection_sort, insertion_sort, merge_sort, quick_sort):
        assert func(data) == expected, func.__name__
        assert func([]) == []
        assert func([1]) == [1]
    print("sorting.py: all tests passed")
