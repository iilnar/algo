#include <bits/stdc++.h>

using namespace std;

#define FILENAME "matching"
#define x first
#define y second
#define mp make_pair

int n;
vector <vector <pair <int, long long> > > edge;
vector <pair <long long, long long> > ans;

void dfs (int v, int from) { 
    for (int i = 0; i < edge[v].size(); i++) {
        int to = edge[v][i].x;
        if (to != from) {
            dfs(to, v);
            ans[v].x += max(ans[to].x, ans[to].y);
        }
    }
    long long num = ans[v].x;
    for (int  i = 0; i < edge[v].size(); i++) {
        num = ans[v].x;
        int to = edge[v][i].x;
        if (to == from) continue;
        num = num - max(ans[to].x, ans[to].y) + ans[to].x;
        ans[v].y = max(ans[v].y, num + edge[v][i].y);
    }
}

int main () {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n;
    edge.resize(n + 1);
    ans.resize(n + 1);
    for (int i = 1, q, w, e; i < n; i++) {
        cin >> q >> w >> e;
        edge[q].push_back(mp(w, e));
        edge[w].push_back(mp(q, e));
    }
    dfs(1, 0);
/*    for (int i = 1; i <= n; i++) {
        cout << i << " notIncluded: " << ans[i].x << " included: " << ans[i].y << "\n";
    }
*/
    cout << max(ans[1].x, ans[1].y);
}