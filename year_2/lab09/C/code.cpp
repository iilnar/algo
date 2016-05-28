#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

#define FILENAME "p1outtreewc"

using namespace std;

int dsu_get(vector <int> &parent, int x) {
    if (x == parent[x]) {
        return x;
    }
    return parent[x] = dsu_get(parent, parent[x]);
}

void dsu_union(vector <int> &parent, int x, int y) {
    parent[dsu_get(parent, x)] = dsu_get(parent, y);
}

struct job {
    long long p, w;
    int id, par, prev;

    void append(job* other) {
        other->par = prev;
        prev = other->prev;
        p += other->p;
        w += other->w;
    }
};

int main() {
    freopen(FILENAME".in", "r", stdin); freopen(FILENAME".out", "w", stdout);
    int n;
    cin >> n;
    vector <job> jobs(n);
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].p;
        jobs[i].id = i;
        jobs[i].prev = i;
        jobs[i].par = -1;
    }
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].w;
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        jobs[x - 1].par = y - 1;
    }
    int root = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].par == -1) {
            root = i;
        }
    }
    vector <job> copy(jobs);
    vector <int> dsu(n);
    for (int i = 0; i < n; i++) {
        dsu[i] = i;
    }
    auto comp = [root](job* a, job* b) -> bool {
        if (a->id == b->id || a->id == root) {
            return false;
        }
        if (b->id == root) {
            return true;
        }
        return a->w * b->p > a->p * b->w || (a->w * b->p == a->p * b->w && a->id < b->id);
    };
    auto se = set <job*, decltype(comp)>(comp);
    for (int i = 0; i < n; i++) {
        se.insert(&jobs[i]);
    }
    while ( se.size() > 1) {
        auto e = se.begin();
        auto point = *e;
        se.erase(e);
        int i = dsu_get(dsu, point->par);
        se.erase(&jobs[i]);
        jobs[i].append(point);
        se.insert(&jobs[i]);
        dsu_union(dsu, point->id, i);
    }
    int j = (*se.begin())->prev;
    vector <int> ls;
    while (j != -1) {
        ls.push_back(j);
        j = jobs[j].par;
    }
    long long t = 0, res = 0;
    vector <long long> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        ans[ls[i]] = t;
        t += copy[ls[i]].p;
        res += t * copy[ls[i]].w;
    }
    cout << res << '\n';
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            cout << ' ';
        }
        cout << ans[i];
    }
    cout << '\n';
}
