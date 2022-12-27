#include <bits/stdc++.h>
using namespace std;

// void bubbleSort(int a[], int n) {
//     bool check = false;
//     for (int i = 0; i < n - 1; i++) {
//         check = false;
//         for (int j = 0; j < n - i - 1; j++) {
//             if (a[j] > a[j + 1]) {
//                 swap(a[j], a[j + 1]);
//                 check = true;
//             }
//         }
//         // IF no two elements were swapped by inner loop, then break
//         if (!check) {
//             break;
//         }
//     }
// }

void bubbleSort(int a[], int n) {
    for (int i = 0; i <= n - 2; i++) {
        for (int j = n - 1; j >= i + 1; j--) {
            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
            }
        }
    }
}

int main() {
    int arr[] = {9, 3, 4, 2, 1, 8};
    int n = 6;

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
