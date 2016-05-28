#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> edge;
#define FILENAME "minimax"
#define cost first
#define to second

int t, n, m;
int cur;
vector <vector <edge> > a; 
vector <int> aa, bb, used;

bool dfs (int v) {
    if (used[v]) {
        return false;
    }
    used[v] = true;
    for (edge e : a[v]) {
        if (cur > e.cost) continue;
        int u = e.to;
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

bool check () {
    bool luck;
    fill(aa.begin(), aa.end(), -1);
    fill(bb.begin(), bb.end(), -1);
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
    return cnt == t;
}

int main() {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n;
    t = n; 
    n += t;
    a.resize(n + 2);
    used.resize(n + 2);
    for (int i = 1; i <= t; i++) {
        a[0].push_back(edge(0, i));
    }
    for (int i = t + 1; i <= n; i++) {
        a[i].push_back(edge(0, n + 1));
    }
    for (int i = 1; i <= t; i++) {
        for (int j = t + 1; j <= n; j++) {
            int p;
            cin >> p;
            a[i].push_back(edge(p, j));
        }
    }
    aa.resize(n + 2, -1);
    bb.resize(n + 2, -1);
    int l = -1, r = (int)1e7;
    while (r - l > 1) {
        cur = l + (r - l) / 2;
        if (check()) {
            l = cur;
        } else {
            r = cur;
        }
    }
    cout << l << '\n';
}
