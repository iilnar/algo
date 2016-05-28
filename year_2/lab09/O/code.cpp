#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

#define FILENAME "qsumci"

using namespace std;

struct task {
    int id, p;
    bool operator<(const task& other) const {
        return p < other.p;
    }
};

struct machine {
    int id, t, delay;
    bool operator<(const machine& other) const {
        return t * delay < other.t * other.delay || (t * delay == other.t * other.delay && id < other.id);
    }
};

int main() {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector <task> tasks(n);
    vector <machine> machines(m);
    vector <vector <int> > queue(m);
    vector <pair <int, long long> > ans(n);
    for (int i = 0; i < n; i++) {
        cin >> tasks[i].p;
        tasks[i].id = i;
    }
    set <machine> se;
    for (int i = 0; i < m; i++) {
        cin >> machines[i].t;
        machines[i].id = i;
        machines[i].delay = 1;
        se.insert(machines[i]);
    }
    for (int i = 0; i < n; i++) {
        machine e = *se.begin();
        se.erase(se.begin());
        queue[e.id].push_back(i);
        e.delay++;
        se.insert(e);
    }
    long long sum = 0;
    sort(tasks.rbegin(), tasks.rend());
    for (int i = 0; i < m; i++) {
        long long curT = 0;
        for (int j = (int)queue[i].size() - 1; j >= 0; j--) {
            ans[tasks[queue[i][j]].id].first = i;
            ans[tasks[queue[i][j]].id].second = curT;
            curT += 1LL * tasks[queue[i][j]].p * machines[i].t;
            sum += curT;
        }
    }
    cout << sum << '\n';
    for (int i = 0; i < n; i++) {
        cout << ans[i].first + 1 << ' ' << ans[i].second << '\n';
    }
}
