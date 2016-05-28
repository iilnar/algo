#include <bits/stdc++.h>

using namespace std;

#define FILENAME "palindrome"

int n;
string a, b;
vector <vector <int> > ans;

int main () {
        freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> a;
    int n = a.size();
    b = a;
    reverse(b.begin(), b.end());
    a = "." + a;
    b = "." + b;
    ans.resize(n + 1, vector <int> (n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i] == b[j]) {
                ans[i][j] = ans[i - 1][j - 1] + 1;
            } else {
                ans[i][j] = max(ans[i - 1][j], ans[i][j - 1]);
            }

        }
    }
    int i = n, j = n;
    stack <char> st;
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
        cout << st.top();
        st.pop();
    }


}