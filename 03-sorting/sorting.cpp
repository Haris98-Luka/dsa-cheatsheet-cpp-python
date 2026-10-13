// Bubble, selection, insertion, merge and quick sort.
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// O(n^2), early exit gives O(n) best case
vector<int> bubbleSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    return arr;
}

// O(n^2)
vector<int> selectionSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int smallest = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[smallest]) smallest = j;
        swap(arr[i], arr[smallest]);
    }
    return arr;
}

// O(n^2) worst, O(n) best
vector<int> insertionSort(vector<int> arr) {
    for (int i = 1; i < (int)arr.size(); i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return arr;
}

// O(n log n), stable, O(n) extra space
vector<int> mergeSort(const vector<int>& arr) {
    if (arr.size() <= 1) return arr;
    size_t mid = arr.size() / 2;
    vector<int> left = mergeSort(vector<int>(arr.begin(), arr.begin() + mid));
    vector<int> right = mergeSort(vector<int>(arr.begin() + mid, arr.end()));
    vector<int> merged;
    size_t i = 0, j = 0;
    while (i < left.size() && j < right.size())
        merged.push_back(left[i] <= right[j] ? left[i++] : right[j++]);
    while (i < left.size()) merged.push_back(left[i++]);
    while (j < right.size()) merged.push_back(right[j++]);
    return merged;
}

// O(n log n) average, O(n^2) worst
void quickSortHelper(vector<int>& arr, int low, int high) {
    if (low >= high) return;
    int pivot = arr[low + (high - low) / 2];
    int i = low, j = high;
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) swap(arr[i++], arr[j--]);
    }
    quickSortHelper(arr, low, j);
    quickSortHelper(arr, i, high);
}

vector<int> quickSort(vector<int> arr) {
    if (!arr.empty()) quickSortHelper(arr, 0, (int)arr.size() - 1);
    return arr;
}

int main() {
    vector<int> data = {64, 25, 12, 22, 11, 25, 90, -3, 0};
    vector<int> expected = data;
    sort(expected.begin(), expected.end());

    assert(bubbleSort(data) == expected);
    assert(selectionSort(data) == expected);
    assert(insertionSort(data) == expected);
    assert(mergeSort(data) == expected);
    assert(quickSort(data) == expected);
    assert(quickSort({}).empty());
    cout << "sorting.cpp: all tests passed\n";
    return 0;
}
