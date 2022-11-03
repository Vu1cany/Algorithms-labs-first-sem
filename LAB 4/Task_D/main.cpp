#include <iostream>
#include <string>

void RadXSort(std::string *arr, int n, int k) {

}

std::string CountingSort(std::string s1) {
    int k = -INT_MAX;
    for (char C: s1) {
        k = std::max((int)C + 1, k);
    }
    int CountArr[k] = { 0 };
    for (char C: s1) {
        CountArr[(int)C] = ++CountArr[(int)C];
    }
    for (int i = 1; i < k; ++i) {
        CountArr[i] = CountArr[i] + CountArr[i-1];
    }
    std::string s1Sort;
    for (int i = s1.size() - 1; i > 0; --i) {
        if (CountArr[(int)s1[i]] == 0) continue;
        s1Sort + s1[i];
        CountArr[(int)s1[i]]--;
    }
    return s1Sort;
}

int main() {
    int n,m,k;
    std::cin >> n >> m >> k;
    std::string stringArr[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> stringArr[i];
    }

    std::string s1Sort = CountingSort(stringArr[0]);
    std::cout << s1Sort;

    /*for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << "\n";
    }*/

    return 0;
}
