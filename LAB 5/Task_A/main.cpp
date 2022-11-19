#include <iostream>

struct Three{
    int data;
    int leftChild;
    int rightChild;
};

void ThreeHeight(Three *array, int &maxH, int height = 0,  int i = 0) {
    //maxH = std::max(maxH, height);
    maxH = maxH > height ? maxH : height;
    if (array[i].leftChild != 0) {
        ThreeHeight(array, maxH, height + 1, array[i].leftChild - 1);
    }

    if (array[i].rightChild != 0) {
        ThreeHeight(array, maxH, height + 1, array[i].rightChild - 1);
    }
}

int main() {
    int n;
    std::cin >> n;

    if (n == 0) {
        std::cout << 0;
        return 0;
    }

    Three arr[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i].data >> arr[i].leftChild >> arr[i].rightChild;
    }


    int max = 0;
    ThreeHeight(arr, max, 1);

    std::cout << max;

    return 0;
}
