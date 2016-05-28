#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>

using namespace std;

#define FILENAME "p1sumu"

struct job {
    int id, deadline, p;

    bool operator<(const job& a) const {
        return p > a.p || (p == a.p && id < a.id);
    }
};

int main() {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    int n;
    cin >> n;
    vector <job> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].p >> a[i].deadline;
        a[i].id = i;
    }
    sort(a.begin(), a.end(), [](const job& a, const job& b) {
        return a.deadline < b.deadline;
    });
    set <job> s;
    long long t = 0;
    for (int i = 0; i < n; i++) {
        t += a[i].p;
        s.insert(a[i]);
        if (t > a[i].deadline) {
            t -= s.begin()->p;
            s.erase(s.begin());
        }
    }
    cout << s.size() << '\n';
    vector <long long> ans(n);
    long long last = 0;
    for (int i = 0; i < n; i++) {
        ans[a[i].id] = -1;
        if (s.find(a[i]) != s.end()) {
            ans[a[i].id] = last;
            last += a[i].p;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            cout << ' ';
        }
        cout << ans[i];
    }
    cout << '\n';
}
