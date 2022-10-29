#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int k = 0;
    for (int i = 1; i < n-1; ++i) {
        if (arr[i-1] < arr[i] && arr[i] > arr[i+1]) ++k;
    }

    cout << k;
    return 0;
}