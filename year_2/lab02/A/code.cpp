#include <bits/stdc++.h>

using namespace std;
#define FILENAME "components"

int n, m, c;
vector <vector <int> > a;
vector <int> comp;

void dfs(int v) {
    if (comp[v] != 0) {
        return;
    }
    comp[v] = c;
    for (auto u : a[v]) {
        dfs(u);
    }
}

int main() {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n >> m;
    a.resize(n);
    comp.resize(n);
    for (auto i = 0, u = 0, v = 0; i < m; i++) {
        cin >> u >> v;
        a[u - 1].push_back(v - 1);
        a[v - 1].push_back(u - 1);        
    }
    for (auto i = 0; i < n; i++) {
        if (comp[i] == 0) {
            c++;
            dfs(i);
        }
    }
    cout << c << '\n';
    for (auto i = 0; i < n; i++) {
        cout << comp[i] << ((i == n - 1) ? '\n' : ' ');
    }
}
