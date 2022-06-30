#include <bits/stdc++.h>
using namespace std;

void quickSort(int a[], int l, int r) {
    int i = l, j = r;
    int key = a[(l + r) / 2];
    while (i <= j) {
        while (a[i] < key) i++;
        while (a[j] > key) j--;

        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (i < r) quickSort(a, i, r);
    if (l < j) quickSort(a, l, j);
}

int main() {
    int arr[] = {9, 3, 4, 2, 1, 8};
    int n = 6;

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
