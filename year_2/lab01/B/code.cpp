#include <bits/stdc++.h>

using namespace std;

#define FILENAME "cond"

int n, m, k = 1;
vector <vector <int> > a, b;
vector <int> ts, color;

void dfs (int v) {
    color[v] = 1;
    for (auto i = 0; i < a[v].size(); i++) {
        if (color[a[v][i]] != 1) {
            dfs(a[v][i]);
        }
    }
    color[v] = 1;
    ts.push_back(v);
}

void paint(int v) {
    color[v] = k;
    for (auto i = 0; i < b[v].size(); i++) {
        if (color[b[v][i]] == 0) {
            paint(b[v][i]);
        }
    }    
}


int main() {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n >> m;
    a.resize(n);
    b.resize(n);
    color.resize(n);
    for (auto i = 0, u = 0, v = 0; i < m; i++) {
        cin >> u >> v;
        a[u - 1].push_back(v - 1);
        b[v - 1].push_back(u - 1);
    }
    for (auto i = 0; i < n; i++) {
        if (color[i] == 0) {
            dfs(i);
        }
    }
    reverse(ts.begin(), ts.end());
    for (auto i = 0; i < n; i++) {
        color[i] = 0;
    }
    for (auto i = 0; i < n; i++) {
        if (color[ts[i]] == 0) {
            paint(ts[i]);
            k++;
        }
    }
    cout << k - 1 << '\n';
    for (auto i = 0; i < color.size(); i++) {
        cout << color[i] << (i + 1 < color.size() ? ' ' : '\n'); 
    }
}