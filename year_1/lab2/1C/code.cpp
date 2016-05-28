#include <bits/stdc++.h>

using namespace std;

int k, n, a[17];

void dfs (int v) {
    if (v == k + 1) {
        for (int i = 1; i <= k; i++) {
            cout << a[i] << ' ';
        }
        cout << "\n";
        return;
    }
    for (int i = a[v - 1] + 1; i <= n; i++) {
        a[v] = i;
        dfs(v + 1);
    }
}

int main () {
    freopen("choose.in", "r", stdin);freopen("choose.out", "w", stdout);
    cin >> n >> k;
    dfs(1);
}