#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <cstdio>

using namespace std;

#define FILENAME "f2cmax"

struct job {
    int id, f1, f2;
    bool operator<(const job& a) const {
        return min(f1, f2) < min(a.f1, a.f2);
    }
};

int main() {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    int n;
    cin >> n;
    vector <job> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].f1;
        a[i].id = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].f2;

    }
    sort(a.begin(), a.end());
    deque <int> d1, d2;
    for (int i = 0; i < a.size(); i++) {
        if (min(a[i].f1, a[i].f2) == a[i].f1) {
            d1.push_back(a[i].id);
        } else {
            d2.push_front(a[i].id);
        }
    }
    sort(a.begin(), a.end(), [](const job& a, const job& b) {
        return a.id < b.id;
    });
    vector <int> list;
    vector <long long> t(n);
    list.insert(list.begin(), d1.begin(), d1.end());
    list.insert(list.end(), d2.begin(), d2.end());
    for (int i = 0; i < n; i++) {
        t[list[i]] = t[list[max(0, i - 1)]] + a[list[i]].f1;
    }
    for (int i = 0; i < n; i++) {
        t[list[i]] = max(t[list[i]], t[list[max(0, i - 1)]]) + a[list[i]].f2;
    }
    cout << t[list[n - 1]] << '\n';
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                cout << ' ';
            }
            cout << list[i] + 1;
        }
        cout << '\n';
    }
}
