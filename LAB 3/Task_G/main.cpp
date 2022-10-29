#include <bits/stdc++.h>

long double BinSearch(int n, long double A) {
    long double min_B = 0;
    long double l = 0;
    long double r = A;
    while (l + 0.000001 < r) {
        long double A1 = A;   //А1 - первая лампочка, самая крайняя
        long double A2 = l + (r - l) / 2.0;     //А2 - вторая лампочка
        long double B = 0.0;
        long double a1 = A1;
        long double a2 = A2;
        for (int i = 2; i < n; ++i) {
            B = 2 * (a2 + 1) - a1;
            if (B <= 0) break;
            a1 = a2;
            a2 = B;
        }
        if (B > 0) {
            r = A2;
            if (min_B == 0) {
                min_B = B;
            } else min_B = std::min(B, min_B);
        } else {
            l = A2;
        }
    }
    return min_B;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    long double A;
    std::cin >> n;
    std::cin >> A;

    long double answer = BinSearch(n, A);
    printf("%.2Lf", answer);

    return 0;
}