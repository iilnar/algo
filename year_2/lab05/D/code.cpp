#include <bits/stdc++.h>
 
using namespace std;
#define FILENAME "paths"
 
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
    cin >> n >> m; 
    a.resize(2 * n + 2);
    used.resize(2 * n + 2);
    for (int i = 1; i <= n; i++) {
        a[0].push_back(i);
        a[n + i].push_back(2 * n + 1);
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(n + v);
    }
    bool luck;
    aa.resize(2 * n + 2, -1);
    bb.resize(2 * n + 2, -1);
    do {
        luck = false;
        for (int i = 0; i < 2 * n + 2; i++) {
            used[i] = 0;
        }       
        for (int i = 1; i <= n; i++) {
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
    cout << n - cnt << '\n';
}