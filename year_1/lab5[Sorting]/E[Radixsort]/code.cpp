#include <bits/stdc++.h>

using namespace std;

#define FILENAME "radixsort"

int n, m, k;
vector <string> a;
vector <vector <string> > b;

int main() {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n >> m >> k;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int j = m - 1; j >=  m - k; j--) {
        b.clear();
        b.resize(26);
        for (int i = 0; i < n; i++) {
            b[a[i][j] - 'a'].push_back(a[i]);
        }
        a.clear();
        for (int i = 0; i < 26; i++) {
            for (int p = 0; p < b[i].size(); p++) {
                a.push_back(b[i][p]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << '\n';
    }
}