#include <bits/stdc++.h>

using namespace std;

#define FILENAME "part2num"

vector <int> v;
int n, k;
char c;

vector <vector <int> > dp (int n) {
    vector <vector <int> > a(n + 1, vector <int> (n + 1, 0));
    a[n][n] = 1;
    for (int i = 0; i <= n; i++) {
        a[i][i] = 1;
        for (int j = i - 1; j >= 0; j--) {
            a[i][j] = a[i - j][j] + a[i][j + 1];
        }
    }
    return a;
}

vector <int> num2part (int n, int k) {
    vector <vector <int> > a = dp(n);
    vector <int> res;
    int last = 1;
    while (n > 0) {
        int i = last;
        for (; i < n; i++) {
            if (k < a[n - i][i]) break; 
            k -= a[n - i][i];
        }
        last = i;
        n -= last;
        res.push_back(last);
    }
    return res;

}

int part2num (int n, vector <int> v) {
    vector <vector <int> > a = dp(n);
    int k = 0;
    int last = 1;
    for (int i = 0; i < v.size(); i++) {
        for (int j = last; j < v[i]; j++) {
            k += a[n - j][j];
        }
        last = v[i];
        n -= v[i];
    }
    return k;
}

int main () {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    while (cin >> k || cin >> c) {
        v.push_back(k);
        n += k;
    }
    cout << part2num(n, v);

}