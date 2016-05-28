#include <bits/stdc++.h>

using namespace std;

bool used[9];
int n, a[9];

void dfs (int v) {
    if (v == n + 1) {
        for (int i = 1; i <= n; i++) {
            cout << a[i] << ' ';    
        }
        cout << "\n";
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            used[i] = true;
            a[v] = i;
            dfs(v + 1);
            used[i] = false;
        }
    }
}

int main () {
    freopen("permutations.in", "r", stdin);freopen("permutations.out", "w", stdout);
    cin >> n;
    dfs(1);
}