#include <bits/stdc++.h>

using namespace std;

#define FILENAME "antiqs"

int n;
vector <int> ans;
         
int main() {
//    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n;
    ans.resize(n);
    ans[0] = 1;
    for (int i = 1; i < n; i++) {
        ans[i] = i + 1;
        swap(ans[i], ans[i / 2]);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
}