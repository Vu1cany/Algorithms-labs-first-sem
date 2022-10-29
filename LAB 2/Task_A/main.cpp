#include <iostream>

using namespace std;

int main() {
    short n, arr[1000], val, num;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cin >> val >> num;

    for (int i = n; i >= 0; --i) {
        if (i == num-1) {
            arr[i] = val;
            break;
        } else {
            arr[i] = arr[i-1];
        }
    }

    for (int i = 0; i <= n; ++i) {
        cout << arr[i] << " ";
    }

}
