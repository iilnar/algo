#include <iostream>
#include <vector>
#include <cstdio>

#define FILENAME "r2cmax"

using namespace std;

struct job {
    int id, f1, f2;
};

int main() {
    freopen(FILENAME".in", "r", stdin); freopen(FILENAME".out", "w", stdout);
    int n;
    const int MAX_T = 105000;
    cin >> n;
    vector <job> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].f1;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].f2;
    }
    vector <vector <int> > dp(2, vector <int> (MAX_T, MAX_T));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < MAX_T; j++) {
            dp[1][j] = dp[0][j] + a[i - 1].f2;
            if (a[i - 1].f1 <= j) {
                dp[1][j] = min(dp[1][j], dp[0][j - a[i - 1].f1]);
            }
        }
        swap(dp[0], dp[1]);
    }
    int ans = MAX_T;
    for (int i = 0; i < MAX_T; i++) {
        ans = min(ans, max(i, dp[0][i]));
    }
    cout << ans << '\n';
}
