#include <bits/stdc++.h>

using namespace std;

#define FILENAME "points"

int n, m;
vector <vector <int> > a;
vector <int> tin, tout, color;
set <int> ans;


void dfs(int v, int p) {
    static int timer = 0;
    color[v] = 1;
    tin[v] = timer++;
    tout[v] = tin[v];
    int c = 0;
    for (auto u : a[v]) {
        if (color[u] == 0) {
            c++;
            dfs(u, v);
            tout[v] = min(tout[v], tout[u]);
            if (tout[u] >= tin[v] && p != -1) {
                ans.insert(v);                 
            }
        } else if (u != p) {
            tout[v] = min(tout[v], tin[u]);
        }
    }
    if (p == -1 && c > 1) {
        ans.insert(v);
    }
    color[v] = 2;
}

int main() {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n >> m;
    a.resize(n);
    color.resize(n);
    tin.resize(n);
    tout.resize(n);
    for (auto i = 0, v = 0, u = 0; i < m; i++) {
        cin >> u >> v;
        a[u - 1].push_back(v - 1);
        a[v - 1].push_back(u - 1);
    }
    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            dfs(i, -1);
        }
    }
    cout << ans.size() << '\n';
    for (auto i = ans.begin(); i != ans.end(); i++) {
        cout << (*i) + 1 << '\n';
    }
}