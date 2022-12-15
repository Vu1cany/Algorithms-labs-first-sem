#include <iostream>

void buildThree(int *arr, int *arrNew, int i, int L, int R, int n) {
    if (L == R - 1) {
        if (L < n) {
            arrNew[i] = arr[L];
        }
        return;
    }
    int mid = (L + R) / 2;
    buildThree(arr, arrNew, 2 * i + 1, L, mid, n);
    buildThree(arr, arrNew, 2 * i + 2, mid, R, n);
    arrNew[i] = arrNew[2 * i + 1] + arrNew[2 * i + 2];
}

int Sum(int *arrNew, int i, int L, int R, int left, int right) {
    if (right <= L || left >= R) {
        return 0;
    } else if (left <= L && R <= right) {
        return arrNew[i];
    }

    int mid = (L + R) / 2;
    return Sum(arrNew, 2 * i + 1, L, mid, left, right) + Sum(arrNew, 2 * i + 2, mid, R, left, right);
}

void SetNew(int *arrNew, int i, int L, int R, int index, int newVal) {
    if (L == R - 1) {
        arrNew[i] = newVal;
        return;
    }

    int mid = (L + R) / 2;
    if (index < mid) {
        SetNew(arrNew, 2 * i + 1, L, mid, index, newVal);
    } else {
        SetNew(arrNew, 2 * i + 2, mid, R, index, newVal);
    }
    arrNew[i] = arrNew[2 * i + 1] + arrNew[2 * i + 2];
}

int main() {
    int n,q;
    std::cin >> n >> q;
    n++;
    if (n == 0) return 0;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = 0;
    }

    int arrNew[4 * n];
    for (int i = 0; i < 4 * n; ++i) {
        arrNew[i] = 0;
    }

    buildThree(arr, arrNew, 0, 0, n, n);


    for (int i = 0; i < q; ++i) {
        char operation;
        int number;
        int value;
        std::cin >> operation >> number >> value;
        switch (operation) {
            case '+':
                arr[number] += value;
                SetNew(arrNew, 0, 0, n, number - 1, arr[number]);
                break;
            case '-':
                arr[number] -= value;
                if (arr[number] < 0) {
                    arr[number] = 0;
                }
                SetNew(arrNew, 0, 0, n, number - 1, arr[number]);
                break;
            case '?':
                std::cout << Sum(arrNew, 0, 0, n, number - 1, value) << "\n";
                break;
        }

    }
    return 0;
}
