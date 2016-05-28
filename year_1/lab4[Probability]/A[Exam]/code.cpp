#include <bits/stdc++.h>

using namespace std;

#define FILENAME "exam"

int k, n;
vector <double> p, m;

int main () {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> k >> n;
    p.resize(k);
    m.resize(k);
    int pp, mm;
    for (int i = 0; i < k; i++) {
        cin >> pp >> mm;
        p[i] = 1. * pp / n;
        m[i] = mm / 100.;
    }
    double ans = 0;
    for (int i = 0; i < k; i++) {
        ans = ans + p[i] * m[i];
    }
    cout << fixed << setprecision(10) << ans << "\n";
}
