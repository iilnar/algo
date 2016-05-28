#include <bits/stdc++.h>

using namespace std;

int main () {
    freopen("countpaths.in", "w", stdout);
    long long n =200000;
/*    cout << n << ' ' << n * (n - 1) / 2 << "\n";
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cout << i << ' ' << j << "\n";
        }
    }
    cout << "\n";
    return 0;    */
    n = 50000;
    cout << n << ' ' << (n - 1) << "\n";
    for (int i = 2; i <= n; i++) {
        cout << i - 1 << ' ' << i << "\n";
    }
}