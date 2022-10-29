#include <iostream>

using namespace std;

void merge(int arr[], int left, int mid, int right);

void mergeSort(int arr[], int left, int right) {
    if (left + 1 >= right) {
        return;
    }
    int mid = (left+right) / 2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid,right);
    merge(arr,left,mid,right);
}

void merge(int arr[], int left, int mid, int right) {
    int it1 = 0, it2 = 0;
    int sortArr[right-left];
    while ((left + it1 < mid) && (mid + it2 < right)) {
        if (arr[left + it1] < arr[mid + it2]) {
            sortArr[it1+it2] = arr[left+it1];
            it1++;
        } else {
            sortArr[it1+it2] = arr[mid+it2];
            it2++;
        }
    }
    while (left + it1 < mid) {
        sortArr[it1+it2] = arr[left+it1];
        it1++;
    }
    while (mid + it2 < right) {
        sortArr[it1+it2] = arr[mid+it2];
        it2++;
    }
    for (int i = 0; i < it1+it2; ++i) {
        arr[left + i] = sortArr[i];
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    mergeSort(arr,0,n);

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}
