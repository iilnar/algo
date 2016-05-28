#include <bits/stdc++.h>

using namespace std;

#define FILENAME "num2brackets"

long long k;
int n;

string num2brackets (int n, long long k) {
    string s = "";
    vector <vector <long long> > d;
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
    for (int i = 1; i <= 2 * n; i++) {
            if (dep < n && d[2 * n - i][dep + 1] >= k) {
                s += "(";
                dep++;    
            } else {
                s += ")";
                if (dep < n) {
                    k -= d[2 * n - i][dep + 1];
                }
                dep--;
            }
    }
    return s;
}


int main () {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n >> k;
    cout << num2brackets(n, k + 1);
}