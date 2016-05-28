#include <bits/stdc++.h>
 
using namespace std;
#define FILENAME "salesman"
 
int n, m;
vector <vector <long long> > g;
vector <vector <long long> > ans;
const long long INF = 1e13;
 
 
int main () {
        freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
        cin >> n >> m;
        g.resize(n, vector <long long> (n, INF));
        ans.resize(n, vector <long long> ((1 << n), INF));
        for (int i = 0; i <n; i++) {
            ans[i][1 << i] = 0;
        }
        for (int q, w, cost, i = 0; i < m; i++) {
                cin >> q >> w >> cost;
                g[q - 1][w - 1] = cost;
                g[w - 1][q - 1] = cost;
        }
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) {
                for (int j = 0; j < n; j++) {
                    if ((mask >> j) & 1) {
                        ans[i][mask] = min(ans[i][mask], g[j][i] + ans[j][mask - (1 << i)]);
                    }
                }    
            }
        }
    }
    long long mn = INF;
    for (int i = 0; i < n; i++) {
        mn = min(mn, ans[i][(1 << n) - 1]);
    }
    if (mn >= INF) {
        mn = -1;    
    }
    cout << mn << "\n";
}