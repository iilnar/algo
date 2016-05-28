#include <bits/stdc++.h>

using namespace std;

string s;
list <char> l;
list <char>::iterator it;

int main () {
    freopen("mtf.in", "r", stdin);freopen("mtf.out", "w", stdout);
    cin >> s;
    for (char i = 'a'; i <= 'z'; i++) {
        l.push_back(i);
    }
    for (int i = 0; i < s.size(); i++) {
        int k = 0;
        for (it = l.begin(); it != l.end(); it++) {
            k++;
            if ((*it) == s[i]) {
                break;
            } 
        }    
        if (it == l.end()) {
            cout << l.size() + 1 << ' ';
        } else {
            cout << k << ' ';
            l.erase(it); 
        }
        l.push_front(s[i]);
    }
}