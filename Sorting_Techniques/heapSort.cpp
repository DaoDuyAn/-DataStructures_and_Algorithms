#include <bits/stdc++.h>
using namespace std;

void heapify(int a[], int n, int i) {
    int largest = i;    // Initialize largest as root
    int l = 2 * i + 1;  // left = 2*i + 1
    int r = 2 * i + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (l < n && a[l] > a[largest]) largest = l;

    // If right child is larger than largest so far
    if (r < n && a[r] > a[largest]) largest = r;

    // If largest is not root
    if (largest != i) {
        swap(a[i], a[largest]);

        // Recursively heapify the affected sub-tree
        heapify(a, n, largest);
    }
}
void heapSort(int a[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);  // create Max heap.
    }

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(a[0], a[i]);  // swap first and last node

        // call max heapify on the reduced heap
        heapify(a, i, 0);  // create Max heap on reduced array
    }
}

int main() {
    int arr[] = {9, 3, 4, 2, 1, 8};
    int n = 6;

    heapSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
