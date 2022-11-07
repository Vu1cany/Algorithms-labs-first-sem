#include <iostream>
#include <string>

std::string* RadixSort(std::string *ArrString, int n, int m, int k) {
    for (int i = 0; i < k; ++i) {
        std::string s1;
        for (int j = 0; j < n; ++j) {
            s1 += ArrString[j][m - 1 - i];
        }

        int count = -INT_MAX;
        for (char C: s1) {
            count = std::max((int)C + 1, count);
        }

        int CountArr[count];
        for (int j = 0; j < count; ++j) CountArr[j] = 0;

        for (char C: s1) {
            CountArr[(int)C] = ++CountArr[(int)C];
        }

        for (int j = 1; j < count; ++j) {
            CountArr[j] = CountArr[j] + CountArr[j-1];
        }

        std::string stringArrSort[n];
        for (int j = n - 1; j >= 0; --j) {
            if (CountArr[(int)ArrString[j][m - 1 - i]] != 0) {
                stringArrSort[CountArr[(int)ArrString[j][m - 1 - i]] - 1] = ArrString[j];
                CountArr[(int)ArrString[j][m - 1 - i]]--;
            }
        }
        for (int j = 0; j < n; ++j) ArrString[j] = stringArrSort[j];
    }

    return ArrString;
}

int main() {
    int n,m,k;
    std::cin >> n >> m >> k;
    std::string stringArr[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> stringArr[i];
    }
    std::string *stringArrSort = RadixSort(stringArr, n, m, k);

    for (int i = 0; i < n; ++i) std::cout << stringArrSort[i] << "\n";

    return 0;
}
