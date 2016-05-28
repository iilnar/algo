#include <bits/stdc++.h>

using namespace std;
#define FILENAME "planaritycheck"

vector <vector <int> > a;
vector <int> perm;

bool isKFive(vector <vector <int> > a, vector <int> perm) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < i; j++) {
            if (i == j) continue;
            if (a[perm[i]][perm[j]] == 0) {
                return false;
            }
        }
    }    
//    cerr << "FIVE\n";
    return true;
}

bool check () {
    for (int t = 0; t < 6; t++) {
        vector <vector <int> > b = a;
        int cnt = 0;
        for (int i = 0; i < 6; i++) {
            cnt += a[t][i];
        }
//        cout << cnt << '\n';
        if (cnt != 2) continue;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                if (a[i][t] == 1 && a[t][j] == 1) {
                    b[i][j] = 1;
                }
            }
        }
/*        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                cout << b[i][j];
            }
            cout << '\n';
        }
        cout << '\n';*/
        vector <int> pp(6);
        for (int i = 0; i < 6; i++) {
            pp[i] = i;
        }
        do {
            if (isKFive(b, pp)) {
                return true;
            }
        } while (next_permutation(pp.begin(), pp.end()));
    }
    return false;
}

bool isKThree() {
    for (int i = 0; i < 3; i++) {
        for (int j = 3; j < 6; j++) {
            if (a[perm[i]][perm[j]] == 0) {
                return false;
            }
        }
    }
//    cerr << "THREE\n";
    return true;
}

vector <int> vv;
void dfs (int v) {
    if (v == 15) {
        for (int i = 0; i < vv.size(); i++) {
            cout << vv[i];
        }
        cout << '\n';
        return;
    }
    vv[v] = 0;
    dfs(v + 1);
    vv[v] = 1;
    dfs(v + 1);
}

int main() {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
//    vv.resize(15);
//    dfs(0);
//    return 0;
    int t;
    cin >> t;
    string s;
    getline(cin, s);
    for (int q = 0; q < t; q++) {
        getline(cin, s);
        int m = s.size();
        int n = (1 + sqrt(1 + 8 * m)) / 2;
        if (n <= 4) {
            cout << "YES\n";
            continue;
        }
        if (n == 5) {
            if (s == "1111111111") {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
            continue;
        }
        a.clear();
        a.resize(n, vector <int> (n, 0));
        int p = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (s[p++] == '1') {
                    a[i][j] = 1;                
                    a[j][i] = 1;
                }
            } 
        }
        perm.resize(n);
        for (int i = 0; i < n; i++) {
            perm[i] = i;
        }
        string ans = "YES";
        if (check()) {
            ans = "NO";
        }
        do {
            if (isKFive(a, perm) || isKThree()) {
                ans = "NO";
            }
        } while (next_permutation(perm.begin(), perm.end()));
        cout << ans << "\n";
    }
}