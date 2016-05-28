#include <bits/stdc++.h>

using namespace std;

#define FILENAME "lcs"

int n, m;
vector <int> a, b;
vector <vector <int> > ans;

int main () {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> m;
    b.resize(m + 1);
    ans.resize(n + 1, vector <int> (m + 1));
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                ans[i][j] = ans[i - 1][j - 1] + 1;
            } else {
                ans[i][j] = max(ans[i - 1][j], ans[i][j - 1]);
            }

        }
    }
    int i = n, j = m;
    stack <int> st;
    while (i > 0 && j > 0) {
        if (a[i] == b[j]) {
            st.push(a[i]);
            i--;
            j--;
        } else {
            if (ans[i - 1][j] > ans[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
    }
    cout << st.size() << "\n";
    while (!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }
    cout << '\n';
}