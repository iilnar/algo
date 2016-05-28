#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <set>

using namespace std;

#define FILENAME "pathmgep"
#define edge pair <int, int>  
#define mp make_pair
const long long INF = (long long)1e18 + 7;
int n, m, s, t;
vector <vector <long long> > a;
vector <long long> ans;
vector <int> used;

int main() {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n >> s >> t;
    a.resize(n + 1, vector <long long> (n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%lli", &a[i][j]);
        }
    }
    ans.resize(n + 1, INF);
    used.resize(n + 1);
    ans[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = 0;
        for (int j = 1; j <= n; j++) {
            if (!used[j] && ans[j] < ans[v]) {
                v = j;
            }
        }
        used[v] = true;
        for (int j = 1; j <= n; j++) {
            if (a[v][j] != -1) {
                ans[j] = min(ans[j], ans[v] + a[v][j]);
            }        
        }
    }
    if (ans[t] == INF) {
        ans[t] = -1;
    }
    printf("%lli", ans[t]);
}
