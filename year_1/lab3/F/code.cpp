#include <bits/stdc++.h>

using namespace std;

#define FILENAME "matrix"
#define x first
#define y second
#define mp make_pair

int n;
//vector <pair <int, int> > a;
//vector <vector <pair <int, string> > > dp;
pair <int, int> a[401];
pair <int, int> dp[401][401];
string s;

pair <int, int> dfs (int l, int r) {
    if (l == r) {
        return mp(0, l);                
    }
    if (dp[l][r].x > 0) {
        return dp[l][r];
    }
    pair <int, int> f, s, best;
    best.x = 1e9;
    for (int i = l; i < r; i++) {
        f = dfs(l, i);
        s = dfs(i + 1, r);
        if (a[l].x * a[i].y * a[r].y + f.x + s.x < best.x) {
            best.x = a[l].x * a[i].y * a[r].y + f.x + s.x;
            best.y = i;
        }
    }
    dp[l][r] = best;
//    cout << l << ' ' << r << ' ' << best.x << "\n";
    return best;
}

string getAns (int l, int r) {
    if (l == r) {
        return "A";
    }
    return "(" + getAns(l, dp[l][r].y) + getAns(dp[l][r].y + 1, r) + ")";
}

int main () {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n;
//    dp.resize(n + 1, vector <pair <int, string> > (n + 1));
//    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    dfs(1, n);
    cout << dp[1][n].x << "\n";
    cout << getAns(1, n);
}