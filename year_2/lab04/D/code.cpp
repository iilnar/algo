#include <bits/stdc++.h>

using namespace std;
#define FILENAME "euler"

int n;
map <pair <int, int>, int> s;
vector <int> used, oddList;
vector <int> pos;
vector <vector <int> > a;

void dfs(int v) {
    if (used[v]) return;
    used[v] = 1;
    for (int i = 0; i < a[v].size(); i++) {
        dfs(a[v][i]);
    }
}

void euler(int v) {
    while (pos[v] < a[v].size()) {
        if (s[make_pair(v, a[v][pos[v]])] != 0) {
            s[make_pair(v, a[v][pos[v]])]--;
            s[make_pair(a[v][pos[v]], v)]--;
            euler(a[v][pos[v]++]);
        } else {
            pos[v]++;
        }
    }
    cout << v + 1 << ' ';
}

int main() {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n;
    used.resize(n);
    pos.resize(n);
    a.resize(n);
    int sum = 0;    
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        sum += k;
        for (int j = 0; j < k; j++) {
            int p;
            cin >> p;
            a[i].push_back(p - 1);
            s[make_pair(i, p - 1)]++;
        }
        if (k % 2 == 1) {
            oddList.push_back(i);
        }
    }
    int v;
    if (oddList.size() == 0) {
        v = 0;
    } else if (oddList.size() == 1) {
        v = oddList[0];
    } else if (oddList.size() == 2) {
        v = oddList[0];
//        a[oddList[0]][oddList[1]] = 1;
//        a[oddList[1]][oddList[0]] = 1;
    } else {
//        cout << "-1\n";
        return 0;
    }
/*    
    bool painted = false;
    for (int i = 0; i < n; i++) {
        if (a[i].size() > 0 && used[i] == 0) {
            if (!painted) {
                dfs(i);
                painted = true;
            } else {
                cout << "-1\n";
                return 0;
            }
        }
    }    
*/
    cout << sum / 2 << '\n';
    euler(v);
    return 0;
/*    
    stack <int> st;
    st.push(v);
    while (!st.empty()) {
        v = st.top();
        cerr << v << '\n';
        if (a[v].size() - pos[v] == 0) {
            cout << v << ' ';
            st.pop();
        } else {
            st.push(a[v][pos[v]++]);
        }
    }
*/
}
