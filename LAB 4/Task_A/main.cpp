#include <iostream>

bool Is_pyramid(int *arr, int n) {
    for (int i = 0; i < n/2; ++i) {
        if (2*i + 1 < n && arr[2*i + 1] >= arr[i]) {
            if (2*i + 2 < n && arr[2*i + 2] < arr[i]) return false;
        } else return false;
    }
    return true;
}

int main() {
    int n;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    printf(Is_pyramid(arr, n)? "YES" : "NO");

    return 0;
}