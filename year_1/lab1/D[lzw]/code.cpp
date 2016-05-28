#include <bits/stdc++.h>

using namespace std;

string s, t, p;
vector <string> a;

int check (string s) {
    for (int i = 0; i < a.size(); i++) {
        if (s == a[i]) return i;
    }
    return -1;
}

int main () {
    freopen("lzw.in", "r", stdin);freopen("lzw.out", "w", stdout);
    cin >> s;
    for (char i = 'a'; i <= 'z'; i++) {
        t = i;
        a.push_back(t);
    }
    t = "";
    for (int i = 0, r; i < s.size(); i++) {        
        p = t + s[i];
        r = check(p);
        if (r != -1) {
            t += s[i];
        } else {
            a.push_back(p);
            cout << check(t) << ' ';
            t = s[i];
        }
    }
    int r = check(t);
    if (r == -1) {
        a.push_back(t);
        r = a.size() - 1;    
    }    
    cout << r;
}
