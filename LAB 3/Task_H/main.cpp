#include <iostream>

long long MinSum(int *arr, int n, int k, long long sum, int max_element) {
    long long l = max_element-1;
    long long r = sum;

    while (l+1 < r) {
        int count = 0;
        long long mid = (l + r) /2;
        long long arr_sum = 0;

        for (int i = 0; i < n; ++i) {
            if (arr_sum + arr[i] <= mid) {
                arr_sum += arr[i];
            } else {
                arr_sum = arr[i];
                count++;
            }
        }

        if (count >= k) {
            l = mid;
        } else {
            r = mid;
        }

    }
    return l+1;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n,k;
    std::cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    long long sum = 0;
    int max_element = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
        max_element = std::max(max_element, arr[i]);
    }

    long long min_sum = MinSum(arr, n, k, sum, max_element);

    long long arr_sum = 0;
    int count = 0;

    bool pivot_arr[n];
    for (int i = 0; i < n; ++i) pivot_arr[i] = false;

    for (int i = 0; i < n; ++i) {
        if (arr_sum + arr[i] <= min_sum) {
            arr_sum += arr[i];
        } else {
            arr_sum = arr[i];
            pivot_arr[i] = 1;
            count++;
        }
    }
    int new_pivot = n-1;
    while (count < k-1) {
        for (int i = new_pivot; i > 0; --i) {
            if (!pivot_arr[i]) {
                pivot_arr[i] = true;
                new_pivot = i;
                count++;
                break;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (pivot_arr[i]) std::cout << i << " ";
    }

    return 0;
}
