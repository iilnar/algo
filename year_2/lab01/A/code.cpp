#include <bits/stdc++.h>

using namespace std;

#define FILENAME "topsort"

int n, m;
vector <vector <int> > a;
vector <int> ans, color;

void dfs (int v) {
    if (color[v] == 1){
        cout << -1 << '\n';
        exit(0);
    }
    color[v] = 1;
    for (int i = 0; i < a[v].size(); i++) {
        if (color[a[v][i]] != 2) {
            dfs(a[v][i]);
        }
    }
    color[v] = 2;
    ans.push_back(v);
}


int main() {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n >> m;
    a.resize(n);
    color.resize(n);
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        a[u - 1].push_back(v - 1);
    }
    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            dfs(i);
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto i = 0; i < ans.size(); i++) {
        cout << ans[i] + 1 << ' '; 
    }
}