#include <bits/stdc++.h>

using namespace std;

#define FILENAME "game"

int n, m, s;
vector <vector <int> > a;
vector<bool> ans;

void dfs(int v) {
    ans[v] = false;
    if (a[v].size() == 0) {
        return;
    }
    for (auto i = 0, to = 0; i < a[v].size(); i++) {
        to = a[v][i];
        dfs(to);
        if (!ans[to]) {
            ans[v] = true;            
        }    
    }

}


int main() {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n >> m >> s;
    a.resize(n);
    ans.resize(n);
    for (auto i = 0, u = 0, v = 0; i < m; i++) {
        cin >> u >> v;
        a[u - 1].push_back(v - 1);
    }
    dfs(s - 1);                         
    if (ans[s - 1]) {
        cout << "First player wins\n";
    } else {
        cout << "Second player wins\n";
    }
}