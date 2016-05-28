#include <bits/stdc++.h>

using namespace std;
#define FILENAME "mindiff"
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

long long minMST(int first) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    int mn = 0;
    if (first < a.size()) {
        mn = a[first].cost;
    }
    int ans = mn;
    for (int i = first; i < m; i++) {
        if (findSet(a[i].from) != findSet(a[i].to)) {
            unionSet(a[i].from, a[i].to);
            ans = a[i].cost;
        }        
    }
    int color = findSet(0);
    for (int i = 1; i < n; i++) {
        if (color != findSet(i)) {
            return -1;
        }
    }
    return 1LL * ans - 1LL * mn;
}

int main() {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n >> m;
    a.resize(m);
    parent.resize(n);
    
    for (int i = 0; i < m; i++) {
        cin >> a[i].from >> a[i].to >> a[i].cost;
        a[i].from--;
        a[i].to--;
    }
    sort(a.begin(), a.end());
    if (minMST(0) == -1) {
        cout << "NO\n";
        return 0;
    }
    int i = 0;
    long long ans = 2 * (int)1e9 + 7;
    while (i <= m){
        long long res = minMST(i);
        if (res != -1) {
            ans = min(ans, res);    
        }
        i++;
    }
    cout << "YES\n" << ans << '\n';
}