#include <iostream>

using namespace std;

struct Thee {
    int data = 0;
    int leftChild = 0;
    int rightChild = 0;
};

bool IsBinarySearchThree(Thee *array, int parent, int min, int max) {
    int left = array[parent].leftChild - 1;
    int right = array[parent].rightChild - 1;

    if (array[parent].data <= min || array[parent].data >= max){
        return false;
    }

    if (array[parent].leftChild == 0 && array[parent].rightChild == 0) {
        return true;

    } else if (array[parent].leftChild != 0 && array[parent].rightChild != 0) {
        return (IsBinarySearchThree(array, left, min, array[parent].data) && IsBinarySearchThree(array, right, array[parent].data, max));

    }else if (array[parent].leftChild != 0) {
        return IsBinarySearchThree(array, left, min, array[parent].data);

    } else if (array[parent].rightChild != 0) {
        return IsBinarySearchThree(array, right, array[parent].data, max);

    }
}

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << "YES";
        return 0;
    }

    Thee arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].data >> arr[i].leftChild >> arr[i].rightChild;
    }

    int answer = IsBinarySearchThree(arr, 0, INT_MIN, INT_MAX);


    cout << (answer == true ? "YES" : "NO");

    return 0;
}
