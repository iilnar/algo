#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

#define FILENAME "period"

using namespace std;

vector <int> p_function (string s) {
    vector <int> p(s.size());
    for (int i = 1; i < s.size(); i++) {
        p[i] = p[i - 1];
        while (p[i] > 0 && s[i] != s[p[i]]) {
            p[i] = p[p[i] - 1];
        }
        if (s[i] == s[p[i]]) {
            p[i]++;
        }
    }
    return p;
}

vector <int> z_function (string s) {
    vector <int> z(s.size());
    int l = 0, r = 0;
    z[0] = s.size();
    for (int i = 1; i < s.size(); i++) {
        if (i <= r) {
            z[i] = min(z[i - l], r - i + 1);
        }
        while (z[i] + i < s.size() && s[z[i]] == s[z[i] + i]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    string s;
    while (cin >> s) {
        vector <int> p = p_function(s);
        int k = s.size() - p[s.size() - 1];
        cout << ((k > 0 && s.size() % k == 0) ? (k) : s.size())<< '\n';
    }
}