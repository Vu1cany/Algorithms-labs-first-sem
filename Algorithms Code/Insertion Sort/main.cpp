#include <iostream>

void InsertionSort(int *arr, const int n){
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && key < arr[j]) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main() {
    const int N = 10;
    int arr[N] = {100, 10, 2, 5 , 3, 3, 3, 8, 4, 0};
    InsertionSort(arr,N);
    for (int i = 0; i < N; ++i) {
        std::cout << arr[i] << " ";
    }
    return 0;
}