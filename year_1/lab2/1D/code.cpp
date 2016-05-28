#include <bits/stdc++.h>

using namespace std;

int n;
char a[21];

void dfs (int v, int k) {
    if (v == 2 * n + 1) {
        for (int i = 1; i <= 2 * n; i++) {
            cout << a[i];
        }
        cout << "\n";
        return;
    }
    if (k + 1 <= 2 * n - v) {
        a[v] = '(';
        dfs(v + 1, k + 1);
    }
    if (k > 0) {
        a[v] = ')';
        dfs(v + 1, k - 1);
    }

}

int main () {
    freopen("brackets.in", "r", stdin);freopen("brackets.out", "w", stdout);
    cin >> n;
    dfs(1, 0);
}