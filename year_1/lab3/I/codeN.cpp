#include <bits/stdc++.h>
 
using namespace std;
#define FILENAME "salesman"
 
int n, m;
vector <vector <long long> > g;
vector <vector <long long> > ans;
const long long INF = 1e13;
 
 
void print_bits (int x) {
    cout << ' ';
    for (int i = 0; i < n; i++) {
        cout << ((x >> i) & 1);
    }
    cout << "\n";
}
 
long long dfs (int v, int mask) {
//  cout << v << ' ' << mask;
//  print_bits(mask);
        if (ans[v][mask] < INF) {
//          cout << "st\n";
            return ans[v][mask];
        }
        for (int i = 0; i < n; i++) {
            if (g[v][i] < INF && ((mask >> i) & 1)) {
//              cout << i << ' ' << mask - (2 << (i - 1)) << "\n";
//              return 0;
                ans[v][mask] = min(ans[v][mask], g[v][i] + dfs(i, mask - (1 << i)));
                 
            }
        }
//        cout << v << ' ' << mask <<  ' ' << ans[v][mask] << "\n";
//  cout << "d " << v << ' ' << mask << ' ' << ans[v][mask] << "\n";
    cout << v << ' ' << mask << ' ' << ans[v][mask] << "\n";
        return ans[v][mask];
}
 
stack <int> getWay (int v) {
    int mask = (1 << n) - 1;
    stack <int> st;
    st.push(0);
    while (mask) {
        for (int i = 0; i < n; i++) {
            if (g[v][i] < INF && ((mask >> i) & 1) && ans[v][mask] == ans[i][mask - (1 << i)] + g[v][i]) {
                st.push(i);
                v = i;
                mask = mask - (1 << i);
                continue;
            } 
        }
    }
    return st;
}
 
int main () {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME"N.out", "w", stdout);
    cin >> n >> m;
    if (n == 1) {
        cout << 0;
        return 0;
    }
//  print_bits(n);
//  cout << ((n >> m) & 1) << "\n";
//  cout << n - (1 << m) << "\n";
//  print_bits(n - (1 << m));
 
//  return 0;
    g.resize(n, vector <long long> (n, INF));
 
//  for (int i = 0; i < n; i++) g[i][i] = 0;
    for (int q, w, cost, i = 0; i < m; i++) {
        cin >> q >> w >> cost;
        g[q - 1][w - 1] = cost;
        g[w - 1][q - 1] = cost;
    }
    long long an = INF;
    for (int i = 0; i < n; i++) {
        ans.clear();
        ans.resize(n, vector <long long> ((1 << n), INF));
        ans[i][0] = 0;
        for (int j = 0; j < n; j++) {
            ans[i][1 << j] = 0;
        }
        dfs(i, (1 << n) - 1);
        cout << "\n";
//        cout << i << ' ' << dfs(i, (1 << n) - 1) << "\n";
        if (dfs(i, (1 << n) - 1) >= INF) {
                continue;
        }
        stack <int> st = getWay(i);
        st.pop();
        an = min(an, dfs(i, (1 << n) - 1) - g[i][st.top()]);
    }
    if (an >= INF) {
        cout << -1 << "\n";
    } else {
        cout << an << "\n";
    }
}