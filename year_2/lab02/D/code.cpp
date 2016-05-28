#include <bits/stdc++.h>

using namespace std;

#define FILENAME "bipartite"

int n, m;
vector <vector <int> > a;
vector <int> ans;

void dfs(int v, int c = 0, int p = -1) {
    if (ans[v] != 0 && ans[v] != c) {
        cout << "NO\n";
        exit(0);
    }
    if (ans[v] != 0) {
        return;
    }
    ans[v] = c;
    for (auto u : a[v]) {
        dfs(u, (c + 1) % 2, v);        
    }    
}

int main() {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n >> m;
    a.resize(n);
    ans.resize(n);
    for (auto i = 0, v = 0, u = 0; i < m; i++) {
        cin >> v >> u;
        a[v - 1].push_back(u - 1);
        a[u - 1].push_back(v - 1);
    }
    for (auto i = 0; i < n; i++) {
        if (ans[i] == 0) {
            dfs(i);
        }
    }
    cout << "YES\n";
}