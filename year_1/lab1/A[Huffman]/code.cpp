#include <bits/stdc++.h>

using namespace std;

int n;
long long ans;
set <pair <long long, int> > s;
pair <long long, int> a, b;
int main () {
    freopen("huffman.in", "r", stdin);freopen("huffman.out", "w", stdout);
    cin >> n;
    for (int i = 1, k; i <= n; i++) {
        cin >> k;
        s.insert(make_pair(k, i));
    }
    for (int i = 1; i < n; i++) {
        a = (*s.begin());
        s.erase(s.begin());
        b = (*s.begin());
        s.erase(s.begin());
        s.insert(make_pair(a.first + b.first, a.second));
        ans += a.first + b.first;
    }
    cout << ans << "\n";
}