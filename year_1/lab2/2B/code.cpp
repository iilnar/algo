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
 
#define FILENAME "perm2num"
long long n, k;
vector <int> v;
 
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
 
int main () {
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    freopen(FILENAME".in", "r", stdin); freopen(FILENAME".out", "w", stdout);
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << perm2num(n, v);
    return 0;
}