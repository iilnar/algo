#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

#define FILENAME "search3"

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
    string s, t;
    cin >> s >> t;
    vector <int> zf = z_function(s + "#" + t);
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    vector <int> zr = z_function(s + "#" + t);
    vector <int> ans;
    for (size_t i = 0; s.size() + i <= t.size(); i++) {
        int k = zf[s.size() + i + 1];
        int pos = s.size() + 1 + (t.size() - i - s.size());
//        cerr << i << ' ' << k << ' ' << pos << '\n';
        if (k + zr[pos] + 1 >= s.size()) {
            ans.push_back(i + 1);
        }
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ((i + 1 != ans.size()) ? ' ' : '\n');
    }
}