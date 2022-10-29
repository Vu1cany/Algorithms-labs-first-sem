#include <iostream>

using namespace std;

void InsertSort_2Arr(int IdArr[], int ValArr[], int val) {
    for (int i = 1; i < val; ++i) {
        int ValKey = ValArr[i];
        int IdKey = IdArr[i];
        int j = i - 1;
        while (ValArr[j] < ValKey && j >= 0) {
            ValArr[j+1] = ValArr[j];
            IdArr[j+1] = IdArr[j];
            j--;
        }
        while (IdArr[j] > IdKey && ValArr[j] == ValKey && j >= 0) {
            IdArr[j+1] = IdArr[j];
            ValArr[j+1] = ValArr[j];
            j--;
        }
        ValArr[j+1] = ValKey;
        IdArr[j+1] = IdKey;
    }
}

int main() {
    int n;
    cin >> n;
    int IdArr[n],ValArr[n];
    for (int i = 0; i < n; ++i) {
        cin >> IdArr[i] >> ValArr[i];
    }

    InsertSort_2Arr(IdArr,ValArr,n);

    for (int i = 0; i < n; ++i) {
        cout << IdArr[i] << " " << ValArr[i] << endl;

    }

    return 0;
}