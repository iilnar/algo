#include <bits/stdc++.h>

using namespace std;
#define FILENAME "optimalcode"

int n;
const long long INF = 1e13;
vector <vector <int> > a, k;
vector <vector <long long> > dp;
vector <string> ans;

long long dfsOld (int l, int r) {    
    if (l == r) return 0;
    if (dp[l][r] < INF) {
        return dp[l][r];
    }
    long long res = INF;
    for (int i = l; i < r; i++) {
        res = min(res, dfsOld(l, i) + dfsOld(i + 1, r) + a[l][r]);        
    }
    dp[l][r] = res;
    //cnt--;
    return res;
}

void dfs (int len, int l, int r) {
    int L = k[l][r - 1];
    int R = k[l + 1][r];
//    cout << l << ' ' << r << ' ' << L << ' ' << R << ' ';
    for (int i = L; i <= R && i + 1 <= n; i++) {
        long long res = a[l][r] + dp[l][i] + dp[i + 1][r];
        if (res < dp[l][r]) {
            dp[l][r] = res;
            k[l][r] = i;
        }
    }
//    cout << dp[l][r] << '\n';
    if (l + 1 + len <= n) {
            dfs(len, l + 1, l + len + 1);
    }
    if (l == 1 && len + 1 < n) {
        dfs(len + 1, l, l + len + 1);
    }
}

void getAns (int l, int r, string s) {
    if (l == r) {
        ans[l] = s;
        return;
    }
    getAns(l, k[l][r], s + "0");
    getAns(k[l][r] + 1, r, s + "1");
    return;
}

int main () {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n;
    a.resize(n + 1, vector <int> (n + 1));
    dp.resize(n + 1, vector <long long> (n + 1, INF));
    k.resize(n + 1, vector <int> (n + 1));
    ans.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i][i];
    }
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
        k[i][i] = i;
        k[i][min(n, i + 1)] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j >= 1; j--) {
            a[j][i] = a[j + 1][i] + a[j][i - 1] - a[j + 1][i - 1];
        }
    }
    if (n > 1) {
        dfs(1, 1, 2);
    } else {
        cout << a[1][1] << "\n0\n";
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << "\n";
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << k[i][j] << ' ';
        }
        cout << "\n";
    }

    cout << dp[1][n] << "\n";
//    cout << dfs(1, n) << "\n";
    getAns(1, n, "");
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << "\n";
    }
                      `
}