#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iomanip>

using namespace std;

#define FILENAME "absmarkchain"
#define matrix vector <vector <double> >

matrix create (int N, int M) {
    matrix c;
    c.resize(N, vector <double> (M, 0));
    return c;
}

matrix operator* (const matrix &a, const matrix &b) {
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
matrix a, q, r, e, g;
vector <bool> absorbing;
vector <int> id;

int main () {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n >> m;
    a = create(n, n);
    absorbing.resize(n);
    id.resize(n);
    for (int qq, ww, i = 0; i < m; i++) {
        cin >> qq >> ww;
        cin >> a[qq - 1][ww - 1];
        if (qq == ww && a[qq - 1][ww - 1] == 1.) {
            absorbing[qq - 1] = true;
        }
    }
    int na = 0, ab = 0;
    for (int i = 0; i < n; i++) {
        if (!absorbing[i]) {
            id[i] = na++;
        } else {
            id[i] = ab++;
        }
    }
    q = create(na, na);
    r = create(na, ab);
    e = create(na, na);
    g = create(na, ab);
    for (int i = 0; i < na; i++) {
        q[i][i] = 1.;
        e[i][i] = 1.;
    }
    for (int i = 0; i < n; i++) {
        if (!absorbing[i]) {
            for (int j = 0; j < n; j++) {
                if (absorbing[j]) {
                    r[id[i]][id[j]] = a[i][j];
                } else {
                    q[id[i]][id[j]] -= a[i][j];
                }
            }
        }
    }
    for (int i = 0; i < na; i++) {
        double kof = 1.;
        if (q[i][i] != 1.) {
            kof = q[i][i];
            for (int j = 0; j < na; j++) {
                q[i][j] /= kof;
                e[i][j] /= kof;
            }
        }
        for (int j = 0; j < na; j++) {
            if (i != j) {
                kof = q[j][i];
                for (int k = 0; k < na; k++) {
                    q[j][k] -= kof * q[i][k];
                    e[j][k] -= kof * e[i][k];
                }
            }
        }
    }
    g = e * r;
/*    for (int i = 0; i < na; i++) {
        for (int j = 0; j < ab; j++) {
            for (int k = 0; k < na; k++) {
                g[i][j] = g[i][j] + e[i][k] * r[k][j];
            }
        }
    }*/
    cout << fixed << setprecision(10);
    for (int i = 0; i < n; i++) {
        double ans = 0.;
        if (absorbing[i]) {
            for (int j = 0; j < na; j++) {
                ans += g[j][id[i]];
            }
            ans = (ans + 1) / n;
        }
        cout << ans << "\n";
    }
    return 0;
}
