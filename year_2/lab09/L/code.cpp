#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

#define FILENAME "pintreep1l"

using namespace std;

struct job {
        int id, d, nd;
        job* par;
        vector <job *> childs;

        job() : id(0), d(0), nd(0), par(NULL) {
        }

        bool operator<(const job& other) const {
            return nd < other.nd || (nd == other.nd && id < other.id);
        }
};

int main() {
    freopen(FILENAME".in", "r", stdin); freopen(FILENAME".out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector <job*> a(n);
    vector <int> d(n);
    for (int i = 0 ; i < n; i++) {
        cin >> d[i];
        a[i] = new job();
        a[i]->d = d[i];
        a[i]->nd = a[i]->d;
        a[i]->id = i;
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        a[x]->par = a[y];
        a[y]->childs.push_back(a[x]);
    }
    queue <int> que;
    for (int i = 0; i < n; i++) {
        if (a[i]->par == NULL) {
            que.push(i);
        }
    }
    while (que.size() != 0) {
        int t = que.front();
        que.pop();
        for (int i = 0; i < a[t]->childs.size(); i++) {
            a[t]->childs[i]->nd = min(a[t]->childs[i]->nd, a[t]->nd - 1);
            que.push(a[t]->childs[i]->id);
        }
    }
    sort(a.begin(), a.end(), [](job* a, job* b) {
        return a -> nd < b -> nd || (a -> nd == b -> nd && a -> id < b -> id);
    });
    // for (int i = 0; i < n; i++) {
    //     cerr << a[i]->id << ' ' << a[i]->nd << '\n';
    // }
    // cerr << '\n';
    int f = 0;
    vector <int> beg(n), rev(n), q(n);
    for (int i = 0; i < n; i++) {
        int t = max(f, rev[a[i]->id]);
        // cerr << i << ' ' << t << ' ' << a[i]->id << '\n';
        beg[a[i]->id] = t;
        q[t]++;
        if (q[t] == m) {
            f = t + 1;
        }
        if (a[i]->par != NULL) {
            // cerr << a[i]->id << ' ' << a[i]->par->id << '\n';
            rev[a[i]->par->id] = max(rev[a[i]->par->id], t + 1);
        }
    }
    // for (int i = 0; i < n; i++) {
    //     cerr << beg[i] << ' ' << rev[i] << ' ' << q[i] << '\n';
    // }
    int ans = numeric_limits<int>::min();
    for (int i = 0; i < n; i++) {
        ans = max(ans, beg[i] - d[i] + 1);
    }
    cout << ans << '\n';
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            cout << ' ';
        }
        cout << beg[i];
    }
    cout << '\n';
}
