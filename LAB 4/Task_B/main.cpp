#include <iostream>

void SiftDown(int *arr, int n, int i) {
    int root = i;
    while (2*i + 1 < n) {
        if (arr[2*i + 1] > arr[root]) {
            root = 2*i + 1;
        }
        if (2*i + 2 < n && arr[2*i + 2] > arr[root]) {
            root = 2*i + 2;
        }
        if (arr[root] > arr[i]) {
            std::swap(arr[i], arr[root]);
        } else break;

        i = root;
    }
}

void HeapBuild(int *arr, int n) {
    for (int i = n/2; i >= 0; --i) {
        SiftDown(arr, n, i);
    }
}

void HeapSort(int *arr, int n) {
    HeapBuild(arr, n);
    for (int i = n-1; i > 0; --i) {
        std::swap(arr[0],arr[i]);
        SiftDown(arr, i, 0);
    }
}

int main() {
    int n;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    HeapSort(arr,n);

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
