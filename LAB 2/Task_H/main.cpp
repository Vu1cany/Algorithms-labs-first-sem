#include <iostream>

using namespace std;

void merge(int arr1[], int arr2[], int left, int mid, int right) {
    int it1 = 0, it2 = 0;
    int sortArr1[right-left];
    int sortArr2[right-left];
    while ((left + it1 < mid) && (mid + it2 < right)) {
        if (arr1[left + it1] < arr1[mid + it2]) {
            sortArr1[it1+it2] = arr1[left + it1];
            sortArr2[it1+it2] = arr2[left + it1];
            it1++;
        } else {
            sortArr1[it1+it2] = arr1[mid + it2];
            sortArr2[it1+it2] = arr2[mid + it2];
            it2++;
        }
    }
    while (left + it1 < mid) {
        sortArr1[it1+it2] = arr1[left + it1];
        sortArr2[it1+it2] = arr2[left + it1];
        it1++;
    }
    while (mid + it2 < right) {
        sortArr1[it1+it2] = arr1[mid + it2];
        sortArr2[it1+it2] = arr2[mid + it2];
        it2++;
    }
    for (int i = 0; i < it1+it2; ++i) {
        arr1[left + i] = sortArr1[i];
        arr2[left + i] = sortArr2[i];
    }
}

void mergeSort(int arr1[], int arr2[], int left, int right) {
    if (left + 1 >= right) { return; }
    int mid = (left+right) / 2;
    mergeSort(arr1,arr2,left,mid);
    mergeSort(arr1,arr2,mid,right);
    merge(arr1, arr2, left, mid, right);
}

void NewArr(int arr1[], int arr2[], int n) {
    for (int i = 1; i < n; ++i) {
        if (arr2[i-1] > arr1[i] && arr2[i-1] <= arr2[i]) {
            arr1[i] = arr1[i-1];
            arr2[i-1] = 0;
            arr1[i-1] = 0;
        } else if (arr2[i-1] > arr1[i] && arr2[i-1] > arr2[i]) {
            arr1[i] = arr1[i-1];
            arr2[i] = arr2[i-1];
            arr2[i-1] = 0;
            arr1[i-1] = 0;
        } else if (arr2[i-1] == arr1[i]) {
            arr1[i] = arr1[i-1];
            arr2[i-1] = 0;
            arr1[i-1] = 0;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int arrBegin[n],arrEnd[n];
    for (int i = 0; i < n; ++i) {
        cin >> arrBegin[i];
        cin >> arrEnd[i];
    }
    mergeSort(arrBegin,arrEnd,0,n);
    NewArr(arrBegin,arrEnd,n);

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (arrBegin[i] != 0 && arrEnd[i] != 0) {
            sum += arrEnd[i] - arrBegin[i] + 1;
        }
    }

    cout << sum;
    return 0;
}
