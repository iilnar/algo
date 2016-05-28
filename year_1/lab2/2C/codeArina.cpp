#include <bits/stdc++.h>

#define FILENAME "num2choose"
#define pb push_back

using namespace std;

long long n, k, m, last = 1;

vector <long> pas[31];


int main () {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME"ARINA.out", "w", stdout);
    cin >> n >> k >> m;
    pas[0].pb(1);
    for (int i = 1; i <= n; i++) {
        pas[i].pb(1);
        for (int j = 1; j < pas[i - 1].size(); j++) {
            pas[i].pb(pas[i - 1][j - 1] + pas[i - 1][j]);
        }
        pas[i].pb(1);
    }

    for (int i = 1; i <= k; i++) {
        while (m >= pas[n - last][k - i]) {
            m -= pas[n - last][k - i];
            last++;
        }
        cout << last << " ";
        last++;
    }
}