#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = i+1;
    }

    for (int i = 2; i < n; ++i) {
        swap(arr[i], arr[i / 2]);
    }

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n\n";

    return 0;
}