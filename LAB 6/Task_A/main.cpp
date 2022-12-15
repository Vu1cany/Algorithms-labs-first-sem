#include <iostream>

using std::cin;
using std::cout;
using std::max;

struct Three{
    int key;
    int left;
    int right;
};

void BinThreeBalance(Three *array, int *arrHeight, int n) {
    for (int i = 0; i < n; ++i) {
        arrHeight[i] = 0;
    }
    for (int i = n; i > 0; --i) {
        arrHeight[i] = max(arrHeight[array[i - 1].right], arrHeight[array[i - 1].left]) + 1;
    }
}

int main() {
    int n;
    cin >> n;
    Three myThree[n];
    for (int i = 0; i < n; ++i) {
        cin >> myThree[i].key >> myThree[i].left >> myThree[i].right;
    }
    int arrHeight[n+1];
    BinThreeBalance(myThree, arrHeight, n);

    for (int i = 0; i < n; ++i) {
        cout << arrHeight[myThree[i].right] - arrHeight[myThree[i].left] << "\n";
    }

    return 0;
}
