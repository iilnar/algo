#include <bits/stdc++.h>

using namespace std;

#define FILENAME "nextbrackets"

string s;

string next (string s) {
    int i;
    stack <char> st;
    for (i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '(') {
            st.pop();
            if (st.size() > 0) {
                break;    
            }
        }
        if (s[i] == ')') {
            st.push(')');
        }
    }
    if (i < 0) return "-";
    s[i] = ')';
    int open = (s.size() - i - st.size()) / 2;
//    cout << open << "\n";
    i++;
    for (; open >= 1; open--) {
        s[i] = '(';    
        i++;
        st.pop();
    }
    for (i = i; i < s.size(); i++) {
        s[i] = ')';
    }
    return s;
}

int main () {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME"ARINA.out", "w", stdout);
    cin >> s;
    cout << next(s);
}