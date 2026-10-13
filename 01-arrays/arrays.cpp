// Array basics: insert, delete, reverse, rotate, min/max.
#include <algorithm>
#include <cassert>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

// O(n): elements shift right
vector<int> insertAt(vector<int> arr, int index, int value) {
    arr.insert(arr.begin() + index, value);
    return arr;
}

// O(n): elements shift left
vector<int> deleteAt(vector<int> arr, int index) {
    arr.erase(arr.begin() + index);
    return arr;
}

// O(n) time, O(1) space (two pointers)
vector<int> reverseArray(vector<int> arr) {
    int left = 0, right = (int)arr.size() - 1;
    while (left < right) swap(arr[left++], arr[right--]);
    return arr;
}

// O(n)
vector<int> rotateLeft(vector<int> arr, int k) {
    if (arr.empty()) return arr;
    k %= (int)arr.size();
    rotate(arr.begin(), arr.begin() + k, arr.end());
    return arr;
}

// O(n): single pass
pair<int, int> findMinMax(const vector<int>& arr) {
    int smallest = arr[0], largest = arr[0];
    for (int x : arr) {
        smallest = min(smallest, x);
        largest = max(largest, x);
    }
    return {smallest, largest};
}

int main() {
    vector<int> data = {10, 20, 30, 40, 50};
    assert((insertAt(data, 2, 99) == vector<int>{10, 20, 99, 30, 40, 50}));
    assert((deleteAt(data, 1) == vector<int>{10, 30, 40, 50}));
    assert((reverseArray(data) == vector<int>{50, 40, 30, 20, 10}));
    assert((rotateLeft(data, 2) == vector<int>{30, 40, 50, 10, 20}));
    assert((findMinMax(data) == make_pair(10, 50)));
    cout << "arrays.cpp: all tests passed\n";
    return 0;
}
