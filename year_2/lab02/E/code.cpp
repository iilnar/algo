#include <bits/stdc++.h>

using namespace std;

#define FILENAME "bicone"

int n, m, c;
vector <vector <int> > a;
vector <int> tin, tout, color;
map <pair <int, int>, int> mp;
set <int> ans;


void dfs(int v, int p) {
    static int timer = 0;
    color[v] = 1;
    tin[v] = timer++;
    tout[v] = tin[v];
    for (auto u : a[v]) {
        if (color[u] == 0) {
            dfs(u, v);
            tout[v] = min(tout[v], tout[u]);
            if (tout[u] > tin[v]) {
                ans.insert(mp[make_pair(min(u, v), max(u, v))]);                 
            }
        } else if (u != p) {
            tout[v] = min(tout[v], tin[u]);
        }
    }
    color[v] = 2;
}

void paint(int v) {
    color[v] = c;
    for (auto u : a[v]) {
        if (ans.find(mp[make_pair(min(u, v), max(u, v))]) == ans.end() && color[u] == 0) {
            paint(u);
        }
    }
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
        mp[make_pair(min(u, v) - 1, max(u, v) - 1)] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            dfs(i, -1);
        }
    }
    color.clear();
    color.resize(n, 0);
    for (auto i = 0; i < n; i++) {
        if (color[i] == 0) {
            c++;
            paint(i);
        }
    }
    cout << c << '\n';
    for (auto i = 0; i < n; i++) {
        cout << color[i] << ((i == n - 1) ? '\n' : ' ');
    }
}