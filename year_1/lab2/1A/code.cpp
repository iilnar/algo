#include <bits/stdc++.h>

using namespace std;

vector <int> a, b;
int n;

void dfs (int v) {
    if (v == n + 1) {
        for (int i = 1; i <= n; i++) {
            cout << a[i];
        }
        cout << "\n";
        return;
    }
    a[v] = 0;
    dfs(v + 1);
    if (a[v - 1] == 0) {
        a[v] = 1;
        dfs(v + 1);
    }
}

int main () {
    freopen("vectors.in", "r", stdin);freopen("vectors.out", "w", stdout);
    cin >> n;
    a.resize(n + 1);
    b.resize(n + 1);
    b[0] = 1;
    for (int i = 1; i <= n; i++) {
        a[i] = b[i - 1];
        b[i] = a[i - 1] + b[i - 1];
    } 
    cout << a[n] + b[n] << "\n";
    a[0] = 0;
    dfs(1);
}