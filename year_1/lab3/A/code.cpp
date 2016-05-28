#include <bits/stdc++.h>

using namespace std;

#define FILENAME "countpaths"


int n, m, v;
int MOD = 1e9 + 7;
vector <int> ans, need;
vector <bool> used;
vector <vector <int> > a;
queue <int> q;


int main () {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n >> m;
    a.resize(n);
    ans.resize(n);
    need.resize(n);
    for (int qq, w, i = 0; i < m; i++) {
        cin >> qq >> w;
        need[w - 1]++;
        a[qq - 1].push_back(w - 1);
    }
    q.push(0);
    ans[0] = 1;
    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (int i = 0, to; i < a[v].size(); i++) {
            to = a[v][i];
            ans[to] = (ans[v] + ans[to]) % MOD;
            need[to]--;
            if (need[to] == 0) q.push(to);

            
        }
    }
    cout << ans[n - 1];

}