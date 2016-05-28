#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

#define FILENAME "p1p1sumu"

int main() {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    int n, d, d1, d2;
    cin >> n;
    long long a, b, c;
    vector<int> arr(n + 1);
    cin >> d1 >> d2 >> a >> b >> c >> d;
    arr[(d1 <= n) ? d1 : n]++;
    arr[(d2 <= n) ? d2 : n]++;
    for (int i = 2; i < n; i++) {
        int d3 = (a * d1 + b * d2 + c) % d;
        arr[(d3 <= n) ? d3 : n]++;
        d1 = d2;
        d2 = d3;
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < arr[i] && ans < i; j++) {
            ans++;
        }
    }
    cout << ans << '\n';
}
