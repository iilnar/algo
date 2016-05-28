#include <bits/stdc++.h>

using namespace std;

#define FILENAME "perm2num"

int a[19], used[19];
long long k, n, fac;

int main () {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME"ARINA.out", "w", stdout);
    cin >> n;
    fac = 1;
    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
        fac *= i;
    }
    for (int i = 1; i <= n; i++) {
        fac /= (n - i + 1);
        int p = 0;
        for (int j = 1; j < a[i]; j++) {
            if (!used[j]) {
                p++;
            }
        }
        used[a[i]] = true;
        k = k + fac * p;
    }
    cout << k;

}