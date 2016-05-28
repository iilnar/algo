#include <bits/stdc++.h>

using namespace std;
#define FILENAME "matching"

int t, n, m;
vector <vector <int> > a; 
vector <int> aa, bb, used;

bool dfs (int v) {
    if (used[v]) {
        return false;
    }
    used[v] = true;
    for (int u : a[v]) {
        if (bb[u] == -1) {
            aa[v] = u;
            bb[u] = v;
            return true;
        } else {
            if (dfs(bb[u])) {
                aa[v] = u;
                bb[u] = v;
                return true;
            }
        }
    }
    return false;
}

int main() {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> t >> n >> m; 
    n += t;
    a.resize(n + 2);
    used.resize(n + 2);
    for (int i = 1; i <= t; i++) {
        a[0].push_back(i);
    }
    for (int i = t + 1; i <= n; i++) {
        a[i].push_back(n + 1);
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(t + v);
    }
    bool luck;
    aa.resize(n + 2, -1);
    bb.resize(n + 2, -1);
    do {
        luck = false;
        for (int i = 0; i < n + 2; i++) {
            used[i] = 0;
        }        
        for (int i = 1; i <= t; i++) {
            if (aa[i] == -1 && dfs(i)) {
                luck = true;
            }
        }
    } while(luck);
    int cnt = 0;
    for (int i : aa) {
        if (i >= 0) {
            cnt++;
        }
    }
    cout << cnt << '\n';
}
