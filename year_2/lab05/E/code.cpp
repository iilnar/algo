#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <queue>

using namespace std;

#define FILENAME "decomposition"

const int BIG = (int)1e9 + 7;

struct edge {
    int u, v, c, f, id;
    edge* rev;
    edge (int u, int v, int c, int id) : u(u), v(v), c(c), id(id) {
        f = 0;
    }
};

int n, m;
vector <vector <edge*> > edges;
vector <vector <int> > ans;
vector <int> used, beg, dist, flow;

bool bfs (int u, int v, int c) {
    queue <int> q;
    q.push(u);
    fill(dist.begin(), dist.end(), BIG);
    dist[u] = 0;
    while (!q.empty()) {
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

int dfs2 (int u, int v, int f) {
    if (u == v) return f;
    used[u] = 1;
    for (int i  = 0; i < edges[u].size(); i++) {
        edge *e = edges[u][i];
        if (!used[e->v] && 0 < e->f) {
            int df = dfs2(e->v, v, min(f, e->f));
            e->f -= df;
            e->rev->f += df;
            ans[ans.size() - 1].push_back(e->id);
            return df;
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
            edge *e = new edge(u, v, c, i + 1);
            edge *re = new edge(v, u, 0, i + 1);
            e->rev = re;
            re->rev = e;
            edges[u].push_back(e);
            edges[v].push_back(re);
        }
    }
    for (int i = 1 << 29; i >= 1; i >>= 1) {
        while (bfs(0, n - 1, i)) {
            fill(beg.begin(), beg.end(), 0);
            while (dfs(0, n - 1, BIG) > 0) {}
        }
    }
    while (true) {
        fill(used.begin(), used.end(), 0);
        ans.push_back(vector <int>(0));
        int res = dfs2(0, n - 1, BIG);
        if (res == 0) break;
        flow.push_back(res);
    }
    cout << flow.size() << '\n';
    for (int i = 0; i < flow.size(); i++) {
        cout << flow[i] << ' ' << ans[i].size();
        for (int j = ans[i].size() - 1; j >= 0; j--) {
            cout << ' ' << ans[i][j];
        }
        cout << '\n';
    }
    for (auto i : edges) {
        for (edge * j : i)
            delete j;
        i.clear();
    }

}