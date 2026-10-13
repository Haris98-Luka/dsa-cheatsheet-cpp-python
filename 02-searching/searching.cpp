// Linear search and binary search.
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// O(n)
int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < (int)arr.size(); i++)
        if (arr[i] == target) return i;
    return -1;
}

// O(log n), array must be sorted
int binarySearch(const vector<int>& arr, int target) {
    int low = 0, high = (int)arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;  // avoids overflow
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    vector<int> unsorted = {7, 3, 9, 1, 5};
    vector<int> ordered = {1, 3, 5, 7, 9, 11};
    assert(linearSearch(unsorted, 9) == 2);
    assert(linearSearch(unsorted, 4) == -1);
    assert(binarySearch(ordered, 7) == 3);
    assert(binarySearch(ordered, 1) == 0);
    assert(binarySearch(ordered, 4) == -1);
    cout << "searching.cpp: all tests passed\n";
    return 0;
}
