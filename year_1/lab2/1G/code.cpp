#include <bits/stdc++.h>

using namespace std;

int a[11], n, k;

void dfs (int v, int last) {
    if (v == n + 1) {
        if (last != 0) {
            return;
        }
        for (int i = 0; i < k; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[j] == i) {
                    cout << j << " ";
                }
            }
            cout << "\n";
        }
        cout << "\n";
        return;    
    }
    for (int i = 0; i < k - last; i++) {
        a[v] = i;
        dfs(v + 1, last);
    }
    a[v] = k - last;
    dfs(v + 1, last - 1);

}

int main () {
    freopen("part2sets.in", "r", stdin);freopen("part2sets.out", "w", stdout);
    cin >> n >> k;
    dfs(1, k);
}
