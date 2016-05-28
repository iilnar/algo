#include <bits/stdc++.h>

using namespace std;

#define FILENAME "hamiltonian"

int n, m;
vector <vector <int> > a;
vector <int> color, top;

void dfs (int v) {
    color[v] = 1;
    for (auto i = 0; i < a[v].size(); i++) {
        if (color[a[v][i]] != 1) {
            dfs(a[v][i]);
        }
    }
    top.push_back(v);
}

int main() {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n >> m;
    a.resize(n);
    color.resize(n);
    for (auto i = 0, u = 0, v = 0; i < m; i++) {
        cin >> u >> v;
        a[u - 1].push_back(v - 1);
    }
    for (auto i = 0; i < n; i++) {
        if (color[i] == 0) {
            dfs(i);
        }
    }
    reverse(top.begin(), top.end());
    for (auto i = 1; i < n; i++) {
        bool haveEdge = false;
        for (auto j = 0; j < a[top[i - 1]].size(); j++) {
            if (a[top[i - 1]][j] ==  top[i]) {
                haveEdge = true;
                break;
            }
        }
        if (!haveEdge) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}