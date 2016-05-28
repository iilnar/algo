#include <bits/stdc++.h>

using namespace std;

#define FILENAME "brackets2num2"

string s;

long long brackets2num (string s) {
    int n = s.size() / 2, dep = 0;
    long long k = 0;
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
    for (int i = 0; i < 2 * n; i++) {
        if (s[i] == '(') {
            sta.push('(');
            dep++;
            continue;
        }
        if (dep < n) {
            k += d[2 * n - i - 1][dep + 1] * (1 << (2 * n - i - 1 - (dep + 1)) / 2);
        }
                if (s[i] == ')') {
                    sta.pop();
            dep--;
            continue;
        }
        if (!sta.empty() && sta.top() == '(' && dep > 0) {
            k += d[2 * n - i - 1][dep - 1] * (1 << (2 * n - i - 1 - (dep - 1)) / 2);
        }
        if (s[i] == '[') {
            sta.push('[');
            dep++;
            continue;
        }
        if (dep < n) {
            k += d[2 * n - i - 1][dep + 1] * (1 << (2 * n - i - 1 - (dep + 1)) / 2);
        }
        if (s[i] == ']') {
            sta.pop();
            dep--;
        }
    }
    return k;
}

int main () {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> s;
    cout << brackets2num(s);
}