#include <bits/stdc++.h>

using namespace std;
#define FILENAME "spantree2"
#define edge pair <int, pair <int, int> >
#define cost first
#define from second.first
#define to second.second

int n, m;
vector <edge> a;
vector <int> parent;

int findSet(int v) {
    if (parent[v] == v) {
        return v;
    }
    return parent[v] = findSet(parent[v]);
}

void unionSet(int v, int u) {
    parent[findSet(v)] = findSet(u);
}

int main() {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n >> m;
    a.resize(m);
    parent.resize(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> a[i].from >> a[i].to >> a[i].cost;
        a[i].from--;
        a[i].to--;
    }
    long long ans = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < m; i++) {
        if (findSet(a[i].from) != findSet(a[i].to)) {
            unionSet(a[i].from, a[i].to);
            ans += a[i].cost;
        }        
    }
    cout << ans << '\n';
}