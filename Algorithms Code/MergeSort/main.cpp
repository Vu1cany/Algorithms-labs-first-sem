#include <iostream>

void Merge(int *arr, int left, int mid, int right) {
    int it1 = 0, it2 = 0;
    int sortArr[right - left];
    while (left + it1 < mid && mid + it2 < right) {
        if (arr[left + it1] < arr[mid + it2]) {
            sortArr[it1 + it2] = arr[left + it1];
            it1++;
        } else {
            sortArr[it1 + it2] = arr[mid + it2];
            it2++;
        }
    }
    while (left + it1 < mid) {
        sortArr[it1 + it2] = arr[left + it1];
        it1++;
    }
    while (mid + it2 < right) {
        sortArr[it1 + it2] = arr[mid + it2];
        it2++;
    }
    for (int i = 0; i < it1+it2; ++i) {
        arr[left+i] = sortArr[i];
    }
}

void MergeSort(int *arr, int left, int right) {
    if (left + 1 >= right) return;
    int mid = (left+right)/2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid, right);
    Merge(arr, left, mid, right);
}

int main() {
    const int N = 10;
    int arr[N] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    MergeSort(arr, 0, N);
    for (int i = 0; i < N; ++i) {
        std::cout << arr[i] << " ";
    }
    return 0;
}