#include <bits/stdc++.h>

using namespace std;

#define FILENAME "lis"

int n;
vector <int> a, ans, from;

int main () {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n;
    a.resize(n);
    ans.resize(n);
    from.resize(n, -1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        ans[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && ans[i] < ans[j] + 1) {
                ans[i] = ans[j] + 1;
                from[i] = j;    
            }
        }
    }    
    int v = 0;
    for (int i = 0; i < n; i++) {
        if (ans[v] < ans[i]) {
            v = i; 
        }
    }
    cout << ans[v] << "\n";
    stack <int> st;
    while (v != -1) {
        st.push(a[v]);
        v = from[v];
    }
    while (!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }
}