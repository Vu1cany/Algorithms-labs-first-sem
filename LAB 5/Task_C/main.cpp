#include <iostream>

struct Three{
    int data;
    int leftChild;
    int rightChild;
};

void FillThree(Three *arr, int *val, int i = 0) {
    if (arr[i].leftChild != 0 || arr[i].rightChild != 0) {
        if (arr[i].leftChild != 0) {
            FillThree(arr, val, arr[i].leftChild - 1);
        }

        arr[i].data = (*val)++;

        if (arr[i].rightChild != 0) {
            FillThree(arr, val,arr[i].rightChild - 1);
        }
    } else arr[i].data = (*val)++;
}

int main() {
    int n;
    std::cin >> n;
    int value = 1;
    Three arr[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i].leftChild >> arr[i].rightChild;
    }

    int *val = &value;
    FillThree(arr, val);

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i].data << " ";
    }

    return 0;
}