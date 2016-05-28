#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

#define FILENAME "p1sumwu"

struct job {
    int id, d, w;
    bool operator<(const job& a) const {
        return w < a.w || (w == a.w || id < a.id);
    }
};

int main() {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    int n;
    cin >> n;
    vector <job> a(n);
    vector<int> ans(n, -1);
    set<job> s;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i].d  >> a[i].w;
        sum += a[i].w;
        a[i].id = i;
    }
    sort(a.begin(), a.end(), [](const job& a, const job& b) {
        return a.d < b.d || (a.d == b.d && a.w > b.w);
    });
    long long t = 0;
    for (int i = 0; i < n; i++) {
        s.insert(a[i]);
        if (a[i].d > t) {
            t++;
        } else {
            s.erase(s.begin());
        }
    }
    a.clear();
    for (auto e : s) {
        a.push_back(e);
    }
    sort(a.begin(), a.end(), [](const job& a, const job& b) {
        return a.d < b.d || (a.d == b.d && a.w > b.w);
    });
    for (int i = 0; i < (int)a.size(); i++) {
        ans[a[i].id] = i;
        sum -= a[i].w;
    }
    t = a.size();
    cout << sum << '\n';
    for (int i = 0; i < n; i++) {
        if (ans[i] == -1) {
            ans[i] = t++;
        }
        if (i > 0) {
            cout << ' ';
        }
        cout << ans[i];
    }
    cout << '\n';
}
