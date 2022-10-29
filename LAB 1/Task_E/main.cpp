#include <iostream>

using namespace std;

int main() {
    int n,x;
    cin >> n;
    int arr[1000];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cin >> x;
    int min = abs(arr[0] - x), ans = arr[0];
    for (int i = 1; i < n; ++i) {
        if (abs(arr[i] - x) < min) {
            ans = arr[i];
            min = abs(arr[i] - x);
        }
    }
    cout << ans;
    return 0;
}
