#include <iostream>

using namespace std;

int main() {
    short n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        bool flag = 0;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
            flag = 1;
        }
        arr[j+1] = key;
        if (flag) {
            for (int k = 0; k < n; ++k) {
                cout << arr[k] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
