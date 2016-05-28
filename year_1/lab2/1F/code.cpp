#include <bits/stdc++.h>

using namespace std;

int n;
bool used[11];
vector <vector <int> > a;

void dfs (int v) {
    if (v == 0) {
        a.resize(a.size() + 1);
        for (int i = 1; i <= n; i++) {
            if (used[i]) {
                a[a.size() - 1].push_back(i);
            }
        }
        return;
    }
    used[v] = false;
    dfs(v - 1);
    used[v] = true;
    dfs(v - 1);
}


int main () {
    freopen("subsets.in", "r", stdin);freopen("subsets.out", "w", stdout);
    cin >> n;
    dfs(n);
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            cout << a[i][j] << ' ';
        }
        cout << "\n";
    }
}