#include <bits/stdc++.h>

using namespace std;

#define FILENAME "absmarkchain"
#define matrix vector <vector <double> >

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

int n, m;
matrix a, b;

int main () {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME"P.out", "w", stdout);
    cin >> n >> m;
    a = create(n, n);
    b = create(1, n);
    for (int qq, ww, i = 0; i < m; i++) {
        cin >> qq >> ww;
        cin >> a[qq - 1][ww - 1];
    }
    for (int i = 0; i < n; i++) {
        b[0][i] = 1. / n;
    }
    for (int i = 1; i <= 1000; i++) {
        b = b * a;
    }
    cout << fixed << setprecision(10);
    for (int i = 0; i < n; i++) {
        cout << b[0][i] << "\n";
    }

}
