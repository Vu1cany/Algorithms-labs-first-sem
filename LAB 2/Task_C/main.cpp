#include <iostream>

using namespace std;

void InsertSort(int arr[], int length) {
    for (int i = 1; i < length; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (arr[j] > key && j >= 0) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main() {
    int n,m;
    cin >> n >> m;

    int arr[n*m];
    for (int i = 0; i < n*m; ++i) {
        cin >> arr[i];
    }

    int k;
    cin >> k;
    int WeightArr[k];
    for (int i = 0; i < k; ++i) {
        cin >> WeightArr[i];
    }
    InsertSort(arr, n*m);
    InsertSort(WeightArr, k);

    int count = 0;
    for (int i = 0; i < n*m; ++i) {
        for (int j = 0; j < k; ++j) {
            if (WeightArr[j] > arr[i]) { break; }
            if ((WeightArr[j] <= arr[i]) && (arr[i] != 0) && (WeightArr[j] != 0)) {
                ++count;
                WeightArr[j] = 0;
                arr[i] = 0;
            }
        }
    }

    cout << count;

    return 0;
}
