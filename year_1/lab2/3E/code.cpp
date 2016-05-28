#include <bits/stdc++.h>

using namespace std;

#define FILENAME "nextbrackets"

string s;

string nextbrackets (string s) {
        int balance = 0, i = 0;
    for (i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '(') {
            balance++;
            if (balance < 0) {
                break;
            }
        } else {
            balance--;
        }
    }
    if (balance == 0) return "-";
    s[i] = ')';
    int need = (s.size() - i + balance) / 2;
    for (i = i + 1; need > 0; i++ && need--) {
        s[i] = '(';
    }
    for (;i < s.size(); i++) {
        s[i] = ')';
    }                  
    return s;
}

int main () {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> s;
    cout << nextbrackets(s);
}