#include <bits/stdc++.h>

using namespace std;
#define FILENAME "netcheck"

int n, m, k;
bool bad;
vector <bool> a;
vector <pair <int, int> > cmp;

void check() {
    vector <bool> old = a;
    for (int i = 0; i < m; i++) {
        if (a[cmp[i].first] > a[cmp[i].second]) {
            bool tmp = a[cmp[i].first];
            a[cmp[i].first] = a[cmp[i].second];
            a[cmp[i].second] = tmp;
        }
    }
    for (int i = 1; i < n; i++) {
        if (a[i - 1] > a[i]) {
            bad = true;
        }
    }
    a = old;
}

void dfs (int v) {
    if (v == n) {
        check();
        return;
    }
    a[v] = 0;
    dfs(v + 1);
    a[v] = 1;
    dfs(v + 1);

}

int main() {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n >> m >> k;
    a.resize(n);
    cmp.resize(m);
    int cnt = 0;
    for (int i = 0; i < k; i++) {
        int s = 0, x, y;
        cin >> s;
        for (int j = 0; j < s; j++) {
            cin >> x >> y;
            x--;
            y--;
            cmp[cnt].first = min(x, y);
            cmp[cnt].second = max(x, y);
            cnt++;
        }
    }
    dfs(0);
    if (bad) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
}