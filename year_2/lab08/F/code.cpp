#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>

#define FILENAME "count"

using namespace std;

vector <int> sa(const string &s) {
    int n = s.size();
    vector<int> res(n), color(n), nc(n);
    vector <int> tmp(max(150, n), 0), c(max(150, n), 0), sorted(n, 0);
    for (int i = 0; i < n; i++) {
        color[i] = s[i];
        res[i] = i;
        c[color[i]]++;
    }
    for (int i = 1; i < tmp.size(); i++) {
        tmp[i] = tmp[i - 1] + c[i - 1];
    }
    for (int i = 0; i < n; i++) {
        res[tmp[color[i]]++] = i;
    }
    color[res[0]] = 0;
    for (int i = 1; i < n; i++) {
        if (s[res[i - 1]] != s[res[i]]) {
            color[res[i]] = color[res[i - 1]] + 1;
        } else {
            color[res[i]] = color[res[i - 1]];
        }
    }
    for (int l = 1; l <= n; l *= 2) {
        fill(c.begin(), c.end(), 0);
        vector <int> by(n);
        for (int i = 0; i < n; i++) {
            by[i] = (res[i] + n - l) % n;
        }
        tmp[0] = 0;
        for (int i = 0; i < n; i++) {
            c[color[by[i]]]++;
        }
        for (int i = 1; i < n; i++) {
            tmp[i] = tmp[i - 1] + c[i - 1];
        }
        for (int i = 0; i < n; i++) {
            sorted[tmp[color[by[i]]]++] = by[i];
        }
        res = sorted;
        nc[res[0]] = 0;
        for (int i = 1; i < n; i++) {
            int l1 = res[i - 1];
            int l2 = (res[i - 1] + l) % n;
            int r1 = res[i];
            int r2 = (res[i] + l) % n;
            if (color[l1] != color[r1] || color[l2] != color[r2]) {
                nc[r1] = nc[l1] + 1;
            } else {
                nc[r1] = nc[l1];
            }
        }
        color = nc;
    }
    return res;
}

vector <int> lcp(string a) {
    a = a + "#";
    int n = a.size();
    vector <int> suf = sa(a), pos(n), res(n);
    for (int i = 0; i < n; i++) {
        pos[suf[i]] = i;
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        k = max(0, k - 1);
        if (pos[i] == n - 1) {
            res[n - 1] = -1;
            k = 0;
        } else {
            int j = suf[pos[i] + 1];
            while (max(i + k, j + k) < n && a[i + k] == a[j + k]) {
                k++;
            }
            res[pos[i]] = k;
        }
    }
    return res;
}

int main() {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    string s;
    cin >> s;
    vector <int> arr = lcp(s);
    long long sum = s.size() * (1LL * s.size() + 1) / 2;
    for (int i = 0; i < s.size(); i++) {
        sum -= arr[i];
    }
    cout << sum << '\n';
}
