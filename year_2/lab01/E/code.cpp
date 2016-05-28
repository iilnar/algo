#include <bits/stdc++.h>

using namespace std;
#define FILENAME "cycle"

int n, m;
vector <vector <int> > a;
vector <int> color;

void dfs2(int v, int p) {
    cout << v + 1 << ' ';
    color[v] = 2;
    for (auto i = 0; i < a[v].size(); i++) {
        auto to = a[v][i];
        if (/*to != p && */color[to] == 1) {
            dfs2(to, v);
        }
    }    
}

void dfs (int v, int p) {
    if (color[v] == 1) {
        cout << "YES\n";
        dfs2(v, -1);
        cout << '\n';
        exit(0);    
    }
    color[v] = 1;
    for (auto i = 0; i < a[v].size(); i++) {
        auto to = a[v][i];
//        if (to != p) {
            dfs(to, v);
//        }
    }
    color[v] = 2;
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
            dfs(i, -1);
        }
    }
    cout << "NO\n";
}