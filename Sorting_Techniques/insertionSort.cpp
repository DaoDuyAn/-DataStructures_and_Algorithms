#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n) {
    int key, j;
    for (int i = 1; i <= n - 1; i++) {
        key = arr[i];
        j = i;

        // Move elements of arr[0..i-1],
        // that are greater than key, to one
        // position ahead of their
        // current position
        while (j >= 1 and arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}

int main() {
    int arr[] = {9, 3, 4, 2, 1, 8};
    int n = 6;

    insertionSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
