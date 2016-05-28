#include <bits/stdc++.h>

using namespace std;

#define FILENAME "markchain"
#define matrix vector <vector <double> >

matrix p, a;
int n;

matrix create (int N, int M) {
    matrix c;
    c.resize(N, vector <double> (M, 0));
    return c;
}

matrix operator* (const matrix &a, const matrix &b) {
    if (a[0].size() != b.size()) {
        cout << "Error: multiply";
        exit(0);
    }
    matrix c = create(a.size(), b[0].size());
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < a[0].size(); k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}


int main () {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n;
    p = create(n + 1, n + 1);
    a = create(2, n + 1);    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> p[i][j];
        }
        a[1][i] = 1. / n;
    }
    for (int i = 1; i <= 100; i++) {
        a = a * p;
    }
    cout << fixed << setprecision(20);
    for (int i = 1; i <= n; i++) {
        cout << a[1][i] << "\n";
    }
}