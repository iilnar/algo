#include <bits/stdc++.h>

using namespace std;

#define FILENAME "biconv"

int n, m, C;
vector <vector <int> > a;
vector <int> tin, tout, color, used;
map <pair <int, int>, int> mp;
stack <int> st;
set <int> ans;
bool once;

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

void paint(int v, int p, int c) {
    used[v] = 1;
    for (auto u : a[v]) {
        auto id = mp[make_pair(min(u, v), max(u, v))];
        if (!used[u]) {
            if (tin[v] <= tout[u]) {
                color[id] = st.top();
                st.pop();
                paint(u, v, color[id]);
            } else {
                color[id] = c;
                paint(u, v, c);
            }
        } else if (u != p) {
            if (tin[u] <= tin[v]) {
                color[id] = c;
            }
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
    used.resize(n);
    for (auto i = 0, v = 0, u = 0; i < m; i++) {
        cin >> u >> v;
        a[u - 1].push_back(v - 1);
        a[v - 1].push_back(u - 1);
        mp[make_pair(min(u, v) - 1, max(u, v) - 1)] = i;
    }
    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            dfs(i, -1);
        }
    }
    color.clear();
    color.resize(m);
    for (auto i = m + 1; i >= 1; i--) {
        st.push(i);
    }
    for (auto i = 0; i < n; i++) {
        if (used[i] == 0) {
            paint(i, -1, -1);
        }
    }
    cout << st.top() - 1 << '\n';
    for (auto i = 0; i < m; i++) {
        cout << color[i] << ((i == m - 1) ? '\n' : ' ');
    }
    
}