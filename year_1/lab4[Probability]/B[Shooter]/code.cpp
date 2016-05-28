#include <bits/stdc++.h>

using namespace std;

#define FILENAME "shooter"

double kth, sum, p;
int n, m, k;

double power (double a, int x) {
    double res = 1;
    for (int i  = 1; i <= x; i++) {
        res *= a;
    }
    return res;
}

int main () {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> p;
        if (i == k) {
            kth = power((1. - p), m);
        }
        sum += power((1. - p), m);
    }
    cout << fixed << setprecision(20);
    if (sum > 0) {
        cout << kth / sum << "\n";
    } else {
        cout << 0. / n << "\n";
    }
}
