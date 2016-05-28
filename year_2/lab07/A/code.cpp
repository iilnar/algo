#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

#define FILENAME "search1"

using namespace std;

vector <int> p_function (string s) {
    vector <int> p(s.size());
    s = "." + s;
    for (int i = 1; i < p.size(); i++) {
        p[i] = p[i - 1];
        while (p[i] > 0 && s[i + 1] != s[p[i] + 1]) {
            p[i] = p[p[i] - 1];
        }
        if (s[i + 1] == s[p[i] + 1]) {
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
    vector <int> p = p_function(s + "#" + t);
    vector <int> ans;
    for (size_t i = s.size() + 1; i < p.size(); i++) {
        if (p[i] == s.size()) {
            ans.push_back(i - 2 * s.size() + 1);        
        }
    } 
    cout << ans.size() << '\n';
    for (size_t i = 0; i < ans.size(); i++) {
        if (i > 0) {
            cout << ' ';
        }
        cout << ans[i];
    }
    cout << '\n';
}