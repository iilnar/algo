#include <bits/stdc++.h>

using namespace std;

int n, a[41];

void dfs (int v, int k) {
    if (k == 0) {
        for (int i = 1; i < v - 1; i++) {
            cout << a[i] << '+';
        }
        cout << a[v - 1] << '\n';
        return;
    }
    for (int i = a[v - 1]; i <= k; i++) {
        a[v] = i;
        dfs(v + 1, k - i);
    }
}

int main () {
    freopen("partition.in", "r", stdin);freopen("partition.out", "w", stdout);
    cin >> n;
    a[0] = 1;
    dfs(1, n);
}