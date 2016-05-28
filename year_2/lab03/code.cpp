#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n + 2];
    a[0] = 0;
    a[n + 1] = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans += max(0, min(a[i - 1], a[i + 1]) - a[i]);
    }
    cout << ans;
}