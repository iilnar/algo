#include <bits/stdc++.h>

using namespace std;

#define FILENAME "num2brackets2"

long long k;
int n;

string num2brackets (int n, long long k) {
    string s = "";
    vector <vector <long long> > d;
    stack <char> sta;
    d.resize(2 * n + 1, vector <long long> (n + 1, 0));
    d[0][0] = 1;
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j <= n; j++) {
            if (j < n) {
                d[i + 1][j + 1] += d[i][j];
            }
            if (j > 0) {
                d[i + 1][j - 1] += d[i][j];
            }
        }
    }
    int dep = 0;
    long long cur = 0;
    for (int i = 1; i <= 2 * n; i++) {
            if (dep < n) {
                cur = d[2 * n - i][dep + 1] * (1 << (2 * n - i - dep) / 2);
            } else {
                cur = 0;
            }
        if (cur >= k) {
             s += "(";
             sta.push('(');
             dep++;
             continue;
        }
        k -= cur;
        if (!sta.empty() && sta.top() == '(') {
            cur = d[2 * n - i][dep - 1] * (1 << (2 * n - i - dep) / 2 + 1);
        } else {
            cur = 0;
        }
        if (cur >= k) {
            s += ")";
            sta.pop();
            dep--;
            continue;
        }
        k -= cur;
        if (dep < n) {
            cur = d[2 * n - i][dep + 1] * (1 << (2 * n - i - dep) / 2);
        } else {
            cur = 0;
        }
        if (cur >= k) {
            s += "[";
            sta.push('[');
            dep++;
            continue;
        }
        k -= cur;
        s += "]";
        sta.pop();
        dep--;
    }
    return s;
}


int main () {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n >> k;
    cout << num2brackets(n, k + 1);
}