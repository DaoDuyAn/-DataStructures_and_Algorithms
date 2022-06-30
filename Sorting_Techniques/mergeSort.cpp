#include <bits/stdc++.h>
using namespace std;

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int j = 0; j < n2; j++) R[j] = a[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]

    int i = 0;  // Initial index of first subarray
    int j = 0;  // Initial index of second subarray
    int k = l;  // Initial index of merged subarray

    while (i < n1 and j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {  // Copy the remaining elements of L[], if there are any
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {  // Copy the remaining elements of R[], if there are any
        a[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is right index of the sub-array
// of arr to be sorted 
void mergeSort(int a[], int l, int r) {
    if (l >= r) {
        return;  // returns recursively
    }
    int m = l + (r - l) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}
int main() {
    int arr[] = {9, 3, 4, 2, 1, 8};
    int n = 6;

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
