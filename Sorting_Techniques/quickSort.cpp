#include <bits/stdc++.h>
using namespace std;

// void quickSort(int a[], int l, int r) {
//     int i = l, j = r;
//     int key = a[(l + r) / 2];
//     while (i <= j) {
//         while (a[i] < key) i++;
//         while (a[j] > key) j--;

//         if (i <= j) {
//             swap(a[i], a[j]);
//             i++;
//             j--;
//         }
//     }

//     if (i < r) quickSort(a, i, r);
//     if (l < j) quickSort(a, l, j);
// }

// Tìm chốt: 2 phần tử khác nhau đầu tiên, chọn lớn hơn.
int findPivot(int a[], int i, int j) {
    int firstKey = a[i];
    int k = i + 1;

    while (k <= j and a[k] == firstKey) {
        k++;
    }

    if (k > j)
        // KO tìm thấy chốt.
        return -1;
    else {
        if (a[k] > firstKey)
            return k;
        else
            return i;
    }
}

int partition(int a[], int i, int j, int pivot) {
    int L, R;
    L = i, R = j;

    while (L <= R) {
        // Cho R, L chạy.
        while (a[L] < pivot) L++;
        while (a[R] >= pivot) R--;
        // Sai trái, sai phải -> swap.
        if (L < R) swap(a[L], a[R]);
    }
    
    // Trả về điểm phân hoạch.
    return L;  // ai...aL-1; aL...aj
}

void quickSort(int a[], int i, int j) {
    int pivot = findPivot(a, i, j);
    if (pivot != -1) {
        int mid = partition(a, i, j, a[pivot]);
        quickSort(a, i, mid - 1);
        quickSort(a, mid, j);
    }
}
int main() {
    int n = 6;
    int a[] = {9, 3, 4, 2, 1, 8};
    // quickSort(arr, 0, n - 1);
    quickSort(a, 0, 5);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
