#include <iostream>

int BinSearch(int *arr, int n, int key) {
    int l = -1;
    int r = n;
    while (l+1 < r) {
        int m = (l + r) / 2;
        if (arr[m] < key) {
            l = m;
        } else {
            r = m;
        }
    }
    if (arr[r] == key) {
        return r+1;
    } else return -1;
}

int BinSearchRight(int *arr, int n, int key) {
    int l = -1;
    int r = n;
    while (l+1 < r) {
        int m = (l + r) / 2;
        if (arr[m] > key) {
            r = m;
        } else l = m;
    }
    if (arr[l] == key) {
        return l+1;
    } else return -1;
}

int main() {
    int n, m;
    std::cin >> n;
    int arrN[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> arrN[i];
    }
    std::cin >> m;
    int arrM[m];
    for (int i = 0; i < m; ++i) {
        std::cin >> arrM[i];
    }

    for (int i = 0; i < m; ++i) {
        int left = BinSearch(arrN, n, arrM[i]);
        int right = BinSearchRight(arrN, n, arrM[i]);
        std::cout << left << " " << right << "\n";
    }

    return 0;
}