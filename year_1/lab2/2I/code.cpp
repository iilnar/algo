#include <bits/stdc++.h>

using namespace std;

#define FILENAME "num2part"

int n, k;
vector <int> v;


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

int main () {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n >> k;
    v = num2part(n, k);
    for (int i = 0; i < v.size() - 1; i++) {
        cout << v[i] << '+';
    }
    cout << v[v.size() - 1] << "\n";
}
