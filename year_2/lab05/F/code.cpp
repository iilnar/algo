#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <queue>

using namespace std;

#define FILENAME "circulation"

const int BIG = (int)1e9 + 7;

struct edge {
    int u, v, c, f, old, id;
    edge* rev;
    edge (int u, int v, int c) : u(u), v(v), c(c) {
        id = -1;
        f = 0;
    }
    edge(){}
};

int n, m;
vector <vector <edge*> > edges;
vector <edge*> ed;
vector <int> used, beg, dist;

bool bfs (int u, int v, int c) {
    queue <int> q;
    q.push(u);
    fill(dist.begin(), dist.end(), BIG);
    dist[u] = 0;
    while (!q.empty() && dist[v] == BIG) {
        u = q.front();
        q.pop();
        for (int i = 0; i < edges[u].size(); i++) {
            edge *e = edges[u][i];
            if (e->f + c <= e->c && dist[u] + 1 < dist[e->v]) {
                dist[e->v] = dist[e->u] + 1;
                q.push(e->v);
            }
        }
    }
    return dist[v] != BIG;
}

int dfs (int u, int v, int f) {
    if (u == v) return f;
    for (; beg[u] < edges[u].size();) {
        edge *e = edges[u][beg[u]++];
        if (dist[u] + 1 == dist[e->v] && e->f < e->c) {
            int df = dfs(e->v, v, min(f, e->c - e->f));
            if (df > 0) {
                e->f += df;
                e->rev->f -= df;
                return df;
            } 
        }
    }
    return 0;
}

int main() {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n >> m;
    edges.resize(n + 2);
    used.resize(n + 2);
    dist.resize(n + 2);
    beg.resize(n + 2);
    ed.resize(m);
    for (int i = 0; i < m; i++) {
        int u, v, lc, rc;
        cin >> u >> v >> lc >> rc;
        {
            edge *e = new edge(0, v, lc);
            edge *re = new edge(v, 0, 0);
            e->rev = re;
            re->rev = e;
            edges[0].push_back(e);
            edges[v].push_back(re);
        }
        {
            edge *e = new edge(u, v, rc - lc);
            edge *re = new edge(v, u, 0);
            e->old = lc;
            e->rev = re;
            re->rev = e;
            edges[u].push_back(e);
            edges[v].push_back(re);

            ed[i] = e;
        }
        {
            edge *e = new edge(u, n + 1, lc);
            edge *re = new edge(n + 1, u, 0);
            e->rev = re;
            re->rev = e;
            edges[u].push_back(e);
            edges[n + 1].push_back(re);
        }
    }
    for (int i = 1 << 30; i >= 1; i >>= 1) {
        while (bfs(0, n + 1, i)) {
            fill(beg.begin(), beg.end(), 0);
            while (dfs(0, n + 1, BIG)) {
            };
        }
    }
    bool yeah = true;
    for (int i = 0; i < edges[0].size(); i++) {
        edge *e = edges[0][i];
        if (e->c > e->f) {
            yeah = false;
        }
    }
    if (!yeah) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i = 0; i < ed.size(); i++) {
        edge *e  = ed[i];
//        cout << e->u << ' ' << e->v << ' ' << e->f << ' ' << e->old << ' ';
        cout << e->f + e->old << '\n';
    }
}