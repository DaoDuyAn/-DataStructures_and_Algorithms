#include <bits/stdc++.h>
using namespace std;

void selectionSort(int a[], int n) {
    // One by one move boundary of unsorted subarray
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted array
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = i;
                // Swap the found minimum element with the first element
                swap(a[min_idx], a[j]);
            }
        }
    }
}

int main() {
    int arr[] = {9, 3, 4, 2, 1, 8};
    int n = 6;

    selectionSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
