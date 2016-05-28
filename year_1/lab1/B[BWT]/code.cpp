#include <bits/stdc++.h>

using namespace std;

string s;
vector <string> a;

string next (string s) {
    return s.substr(1, s.size() - 1) + s[0];
}

int main () {
    freopen("bwt.in", "r", stdin);freopen("bwt.out", "w", stdout);
    cin >> s;
    for (int i = 1; i <= s.size(); i++) {
        a.push_back(s);
        s = next(s);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++) {
        cout << a[i][s.size() - 1];
    }
    cout << "\n";
}