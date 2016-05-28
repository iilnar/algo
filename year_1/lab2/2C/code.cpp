
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
using namespace std;
 
#define FILENAME "num2choose"
long long n, k, m;
vector <int> ans;
 
vector <int> num2perm (int n, long long k) {
    vector <int> res(n), able;
    vector <long long> fact(n + 1);
    int j;
    fact[0] = 1;
    for (long long i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i;
        able.push_back(i);
    }
    for (int i = 0; i < n; i++) {
        j = k / fact[n - i - 1];
        k %= fact[n - i - 1];
        res[i] = able[j];
        able.erase(able.begin() + j, able.begin() + j + 1);
    }
    return res;
}
 
long long perm2num (int n, vector <int> v) {
    vector <long long> fact(n + 1);
    vector <int> able;
    fact[0] = 1;
    long long res = 0;
    for (long long i = 1; i <= n; i++) { fact[i] = fact[i - 1] * i; able.push_back(i);}
    for (int i = 0; i < v.size(); i++) {
        int j = 0;
        while (able[j] != v[i]) j++;
        able.erase(able.begin() + j, able.begin() + j + 1);
        res += fact[n - i - 1] * j;
    }
    return res;
}
 
vector <vector <long long> > Pascal (int n) {
    vector <vector <long long> > p;
    p.resize(n);
    p[0].push_back(1);
    for (int i = 1; i < n; i++) {
        p[i].push_back(1);
        for (int j = 1; j < p[i - 1].size(); j++) {
            p[i].push_back(p[i - 1][j - 1] + p[i - 1][j]);
        }
        p[i].push_back(1);
    }
    return p;
}
 
vector <int> num2choose (int n, int k, long long m) {
    vector <vector <long long> > pas = Pascal(n);
    vector <int> res(k);
    int j = 0, last = 0;
    for (int i = 0; i < k; i++) {
        j = last + 1;
        while (k - i - 1 >= 0 && m >= pas[n - j][k - i - 1]) {
            m -= pas[n - j][k - i - 1];
            j++;
        }
        res[i] = j;
        last = j;
    }
    return res;
}
 
int main () {
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    freopen(FILENAME".in", "r", stdin); freopen(FILENAME".out", "w", stdout);
    cin >> n >> k >> m;
    ans = num2choose(n, k, m);
    for (int i = 0; i < k; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}