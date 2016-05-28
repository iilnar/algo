#include <bits/stdc++.h>

using namespace std;

#define FILENAME "knapsack"
#define x first
#define y second

int n, m;
vector <pair <int, int> > a;
vector <vector <int> > ans, from;

int main () {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n >> m;
    a.resize(n + 1);
    ans.resize(n + 1, vector <int> (m + 1));
    from.resize(n + 1, vector <int> (m + 1, -1));
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i].y;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (a[i].x <= j) {
                ans[i][j] = max(ans[i - 1][j], ans[i - 1][j - a[i].x] + a[i].y);
            } else {
                ans[i][j] = ans[i - 1][j];
            }
        }
    }
    pair <int, int> v = make_pair(n, m);
    stack <int> st;
    while (ans[v.x][v.y] > 0) {
        if (ans[v.x - 1][v.y] == ans[v.x][v.y]) {
            v.x--;
        } else {
            st.push(v.x);
            v.y -= a[v.x].x;
            v.x--;
        }    
    }
    cout << st.size() << "\n";
    while (!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }
    
}