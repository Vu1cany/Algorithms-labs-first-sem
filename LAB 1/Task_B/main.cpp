#include <iostream>

using namespace std;

int main(void) {
    int n;
    int arr[35];
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int x1 = arr[n-1], x2;
    for (int i = 0; i < n; ++i) {
        x2 = arr[i];
        arr[i] = x1;
        x1 = x2;
    }

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}