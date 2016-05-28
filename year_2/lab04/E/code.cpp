#include <bits/stdc++.h>

using namespace std;
#define FILENAME "chinese"
#define edge pair <long long, pair <int, int> >
#define cost first
#define from second.first
#define to second.second

int n, m;
vector <edge> a;
const long long INF = 1e18;

int checkAll(vector <vector <edge> > &a, int v, vector <bool> &used) {
    if (used[v]) {
        return 0;        
    }    
    int visit = 1;
    used[v] = true;
    for (edge e : a[v]) {
        visit += checkAll(a, e.to, used);
    }
    return visit;        
}

void dfs(int v, vector <int> &tout, vector <vector <edge> > &a, vector <int> &used) {
    if (used[v]) {
        return;
    }    
    used[v] = 1;
    for (edge e : a[v]) {
        dfs(e.to, tout, a, used);
    }
    tout.push_back(v);
}

void dfs(int v, int comp, vector <vector <edge> > &a, vector <int> &used) {
    if (used[v]) {
        return;
    }         
    used[v] = comp;
    for (edge e : a[v]) {
        dfs(e.to, comp, a, used);
    }
}

vector <int> condensation(vector <vector <edge> > &a, int n) {
    vector <vector <edge> > ra(n);
    for (int i = 0; i < n; i++) {
        for (edge e : a[i]) {
            ra[e.to].push_back(make_pair(e.cost, make_pair(e.to, e.from)));
        }
    }
    vector <int> tout;
    vector <int> used(n, 0);
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i, tout, a, used);
        }
    }
    reverse(tout.begin(), tout.end());
    used.clear();
    used.resize(n, 0);
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        if (!used[tout[i]]) {
            dfs(tout[i], cnt++, ra, used);            
        }
    }
    for (int i = 0; i < n; i++) {
        used[i]--;
    }
//    cerr << '\n';
//    for (int i = 0; i < n; i++) {
//        cerr << used[i];
//    }
//    cerr << '\n';
    return used;
}

bool error = false;

long long findMST (vector <edge> &a, int n, int root = 0) {
    long long ans = 0;
    vector <long long> minEdge(n, INF);    
    for (edge e : a) {
        minEdge[e.to] = min(minEdge[e.to], e.cost);
    }
    minEdge[root] = 0;
//    cerr << 'r' << root << '\n';
//    cerr << a.size() << '\n';
    for (int i = 0; i < n; i++) {
        if (i != root) {
            ans += minEdge[i];
//            cerr << i << ' ' << minEdge[i] << '\n';
        }
    }
    for (long long me : minEdge) {
        if (me == INF) {
            error = true;
            return 0;
        }
    }
    vector <vector <edge> > zeroEdges(n);
    for (edge e : a) {
        if (e.cost == minEdge[e.to]) {
            zeroEdges[e.from].push_back(make_pair(0LL, make_pair(e.from, e.to)));
        }
    }
    vector <bool> used(n);
    if (checkAll(zeroEdges, 0, used) == n) {
        return ans;
    }
    vector <int> cond = condensation(zeroEdges, n);
    int condSize = 0;
    for (int siz : cond) {
        condSize = max(condSize, siz + 1);
    }
    vector <edge> newEdges;
    for (edge e : a) {
        if (cond[e.to] != cond[root] && cond[e.from] != cond[e.to]) {
            newEdges.push_back(make_pair(e.cost - minEdge[e.to], make_pair(cond[e.from], cond[e.to])));
//            cerr << e.cost - minEdge[e.to] << ' ' << cond[e.from] << ' ' << cond[e.to] << '\n';
        }        
    }
//    cerr << ans << '\n';
    return ans + findMST(newEdges, condSize, cond[root]);
}

int main() {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n >> m;
    a.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i].from >> a[i].to >> a[i].cost;
        a[i].to--;
        a[i].from--;
    }
    long long ans = findMST(a, n, 0);    
    if (error) {
        cout << "NO\n";
    } else {
        cout << "YES\n"<< ans << '\n';
    }
}
    