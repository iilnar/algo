#include <bits/stdc++.h>

using namespace std;

#define FILENAME "nextvector"

string s;

string nextvector (string s) {
    int i = s.size() - 1;
    while (i >= 0 && s[i] != '0') {
        i--;
    }
    if (i == -1) return "-";
    s[i] = '1';
    for (i = i + 1; i < s.size(); i++) {
        s[i] = '0';
    }
    return s;
}

string prevvector (string s) {
    int i = s.size() - 1;    
    while (i >= 0 && s[i] != '1') {
        i--;
    }
    if (i == -1) return "-";
    s[i] = '0';
    for (i = i + 1; i < s.size(); i++) {
        s[i] = '1';
    }
    return s;
}

string inc(string s)
{
    int l = s.length() - 1;
    while(l >= 0 && s[l] == '1')
    {
        s[l] = '0';
        l--;
    }
    if (l < 0)
        s = '-';
    else
    s[l] = '1';
    return s;
}
 
string dec(string s)
{
    int l = s.length() - 1;
    while(l >= 0 && s[l] == '0')
    {
        s[l] = '1';
        l--;
    }
        if (l < 0)
                s = '-';
        else
                s[l] = '0';
    return s;
}

int main () {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> s;
    cout << prevvector(s) << "\n" << dec(s) << "\n";
    cout << nextvector(s) << "\n" << inc(s);    
}