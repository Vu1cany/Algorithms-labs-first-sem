#include <iostream>

using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int it1 = 0, it2 = 0;
    int arrSort[right-left];
    while ((left + it1 < mid) && (mid + it2 < right)) {
        if (arr[left+it1] < arr[mid+it2]) {
            arrSort[it1+it2] = arr[left+it1];
            it1++;
        } else {
            arrSort[it1+it2] = arr[mid+it2];
            it2++;
        }
    }
    while (left + it1 < mid) {
        arrSort[it1+it2] = arr[left+it1];
        it1++;
    }
    while (mid + it2 < right) {
        arrSort[it1+it2] = arr[mid+it2];
        it2++;
    }
    for (int i = 0; i < it1+it2; ++i) {
        arr[left+i] = arrSort[i];
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left+1 >= right) { return; }
    int mid = (left+right)/2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid,right);
    merge(arr,left,mid,right);
}

int DelSim(int arr[], int n) {
    int NewArr[n];
    int new_n = 1;
    NewArr[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i-1] != arr[i]) {
            NewArr[new_n] = arr[i];
            new_n++;
        }
    }
    for (int i = 0; i < new_n; ++i) {
        arr[i] = NewArr[i];
    }
    return new_n;
}

int main() {
    int n1,n2;
    cin >> n1;
    int arr1[n1];
    for (int i = 0; i < n1; ++i) {
        cin >> arr1[i];
    }
    cin >> n2;
    int arr2[n2];
    for (int i = 0; i < n2; ++i) {
        cin >> arr2[i];
    }
    mergeSort(arr1, 0, n1);
    mergeSort(arr2, 0, n2);

    int new_n1 = DelSim(arr1, n1);
    int new_n2 = DelSim(arr2, n2);
    bool flag = 1;
    if (new_n1 == new_n2) {
        flag = 0;
        for (int i = 0; i < new_n1; ++i) {
            if (arr1[i] != arr2[i]) {
                flag = 1;
                break;
            }
        }
    }

    if (flag) {
        cout << "NO";
    } else {
        cout << "YES";
    }

    return 0;
}
