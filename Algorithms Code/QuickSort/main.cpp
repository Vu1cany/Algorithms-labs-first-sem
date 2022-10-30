#include <iostream>

void QuickSort(int *arr, int left, int right) {
    int i = left;
    int j = right;
    int pivot = arr[(i+j)/2];
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) std::swap(arr[i++], arr[j--]);
    }
    if (left < j) QuickSort(arr, left, j);
    if (right > i) QuickSort(arr, i, right);
}

int main() {
    const int N = 10;
    int arr[N] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    QuickSort(arr, 0, N-1);
    for (int i = 0; i < N; ++i) {
        std::cout << arr[i] << " ";
    }
    return 0;
}