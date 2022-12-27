#include <bits/stdc++.h>
using namespace std;

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted array
        int idx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[idx]) {
                idx = j;
            }
        }
        swap(a[idx], a[i]);
    }
}

// Recursion.

// findMin(int a[], int i, int j) : Returns the index of minimum element between
// arr[i+1] to arr[j].
int findMin(int a[], int i, int j) {
    if (i == j) return i;

    int minpos = findMin(a, i + 1, j);
    if (a[i] < a[minpos]) {
        minpos = i;
    }

    return minpos;
}

void recurselectSort(int a[], int pos, int len) {
    if (pos == len - 2) return;

    int minpos = findMin(a, pos, len - 1);
    if (minpos != pos) {
        swap(a[pos], a[minpos]);
    }

    recurselectSort(a, pos + 1, len);
}
int main() {
    int n = 7;
    int a[] = {9, 3, 4, 2, 1, 8, 10};

    // selectionSort(a, n);
    recurselectSort(a, 0, n);

    for (int i = 0; i < n; i++) cout << a[i] << " ";

    return 0;
}
