#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <queue>

using namespace std;

#define FILENAME "cut"

const int BIG = (int)1e9 + 7;

struct edge {
    int u, v, c, f;
    edge* rev;
    edge (int u, int v, int c) : u(u), v(v), c(c) {
        f = 0;
    }
};

int n, m;
vector <vector <edge> > edges;
vector <int> used, beg, dist;

bool bfs (int u, int v, int c) {
    queue <int> q;
    q.push(u);
    fill(dist.begin(), dist.end(), BIG);
    dist[u] = 0;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int i = 0; i < edges[u].size(); i++) {
            edge *e = &edges[u][i];
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
        edge *e = &edges[u][beg[u]++];
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
    edges.resize(n);
    used.resize(n);
    dist.resize(n);
    beg.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;
        {
            edge *e = new edge(u, v, c);
            edge *re = new edge(v, u, 0);
            e->rev = re;
            re->rev = e;
            edges[u].push_back(*e);
            edges[v].push_back(*re);
        }
        {
            edge *e = new edge(v, u, c);
            edge *re = new edge(u, v, 0);
            e->rev = re;
            re->rev = e;
            edges[u].push_back(*re);
            edges[v].push_back(*e);
        }
    }
    for (int i = 1 << 29; i >= 1; i >>= 1) {
        while (bfs(0, n - 1, i)) {
            fill(beg.begin(), beg.end(), 0);
            while(dfs(0, n - 1, BIG) > 0) {}
        }
    }
    bfs(0, n - 1, 1);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] < BIG) {
            ans++;
        }
    }
    cout << ans << '\n';
    for (int i = 0; i < n; i++) {
        if (dist[i] < BIG) {
            cout << i + 1 << ' ';
        }
    }
    cout << '\n';
}