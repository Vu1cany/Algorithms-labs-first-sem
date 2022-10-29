#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    int min1 = 2147483647, min2 = 2147483647;

    for (int i = 0; i < n; i++) {
        if (arr[i] < min1) {
            min2 = min1;
            min1 = arr[i];
        } else if (arr[i] < min2) {
                min2 = arr[i];
            }
    }
    cout << min1 << " " << min2;

    return 0;
}