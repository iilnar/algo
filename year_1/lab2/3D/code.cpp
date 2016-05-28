#include <bits/stdc++.h>

using namespace std;

#define FILENAME "nextsetpartition"

int n, m, k, num;
vector <vector <int> > v;
string s;

vector <vector <int> > nextsetpartition (vector <vector <int> > a) {
    set <int> s;
    bool luck = false;    
    for (int i = a.size() - 1; i >= 0; i--) {        
        if (s.upper_bound(a[i][a[i].size() - 1]) != s.end()) {
            a[i].push_back((*s.upper_bound(a[i][a[i].size() - 1])));
            s.erase(a[i][a[i].size() - 1]);
            break;
        }
        for (int j = a[i].size() - 1; j >= 0; j--) {
            if (a[i].size() != 1) {
                if (s.upper_bound(a[i][j]) != s.end()) {
                    luck = true;
                    s.insert(a[i][j]);
                    a[i][j] = (*s.upper_bound(a[i][j]));
                    s.erase(a[i][j]);
                    break;
                }
            }
            s.insert(a[i][j]);
            a[i].resize(a[i].size() - 1);
        }
        if (luck) break;
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i].size() == 0) {
            a.erase(a.begin() + i, a.begin() + i + 1);
            i--;
        }
    }
    while (!s.empty()) {
        a.resize(a.size() + 1);
        a[a.size() - 1].push_back((*s.begin()));
        s.erase(s.begin());
    }
    return a;

}

vector <int> parse (string s) {
    vector <int> ret;
    int num = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + (s[i] - '0');
        } else {
            if (num != 0) {
                ret.push_back(num);
            }
            num = 0;
        }
    }
    if (num != 0) ret.push_back(num);
    return ret;
}

vector <int> vec;

int main () {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n >> k;
    while (n != 0 && k != 0) {
        vec = parse(s);
        getline(cin, s);
        v.clear();
        v.resize(k);
        for (int i = 0; i < k; i++) {
            getline(cin, s);
            v[i] = parse(s);
        }
/*        cout << "\ndeb";
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[i].size(); j++) {
                cout << v[i][j] << ' ';
            }
            cout << "\n";
        }    
        cout << "\ndeb";*/
        v = nextsetpartition(v);
        cout << n << ' ' << v.size() << "\n";
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[i].size(); j++) {
                cout << v[i][j] << ' ';
            }
            cout << "\n";
        }
        cout << "\n";
        cin >> n >> k;
    } 
}