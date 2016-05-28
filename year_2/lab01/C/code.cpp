#include <bits/stdc++.h>

using namespace std;

#define FILENAME "shortpath"
#define edge pair <int, long long>  
#define mp make_pair


int n, m, s, t;
const long long INF = 1e18;
vector <vector <edge> > a;
vector <int> color, top;
vector <long long> ans;

void dfs (int v) {
    color[v] = 1;
    for (int i = 0; i < a[v].size(); i++) {
        if (color[a[v][i].first] != 2) {
            dfs(a[v][i].first);
        }
    }
    color[v] = 2;
    top.push_back(v);
}

int main() {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n >> m >> s >> t;
    s--;t--;
    color.resize(n);
    a.resize(n);                                        
    ans.resize(n, INF);
    for (auto i = 0, u = 0, v = 0, c = 0; i < m; i++) {
        cin >> u >> v >> c;
        a[u - 1].push_back(mp(v - 1, c));                
    }
    for (auto i = 0; i < n; i++) {
        if (color[i] == 0) {
            dfs(i);
        }
    }
    reverse(top.begin(), top.end());
    int j = 0;
    ans[s] = 0;
    while (top[j] != s) {j++;}
    for (auto i = j; i < n; i++) {
        for (auto k = 0; k < a[top[i]].size(); k++) {
            auto from = top[i],
                to = a[top[i]][k].first;
            ans[to] = min(ans[to], ans[from] + a[top[i]][k].second);            
        }
    }
    if (ans[t] == INF) {
        cout << "Unreachable\n";
    } else {
        cout << ans[t] << '\n';
    }

}
