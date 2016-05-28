#include <bits/stdc++.h>

using namespace std;

#define FILENAME "lottery"
#define x first
#define y second

int cost, n;
double ans, probability;
vector <pair <int, int> > a;

int main () {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> cost >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    probability = 1. / a[1].x;
    for (int i = 2; i <= n; i++) {
        ans = ans + a[i - 1].y * probability * (a[i].x - 1.)/(a[i].x);
        probability = probability / a[i].x;
    }
    ans += a[n].y * probability;
    cout << fixed << setprecision(20) << cost - ans << "\n";
}