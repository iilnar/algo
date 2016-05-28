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
 
#define FILENAME "num2perm"
long long n, k;
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
 
int main () {
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    freopen(FILENAME".in", "r", stdin); freopen(FILENAME".out", "w", stdout);
    cin >> n >> k;
    ans = num2perm(n, k);
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}