#include <bits/stdc++.h>

using namespace std;
#define FILENAME "spantree"
#define x first
#define y second
#define point pair<int, int>
int n;
const int INF = 1e9;
vector <point> a;
vector <int> dist, used;

int di (point a, point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main() {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n;
    dist.resize(n + 1, INF);
    a.resize(n + 1);
    used.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
    }        
    dist[1] = 0;
    double ans = 0;
    for (int j = 0; j < n; j++) {
        int v = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] < dist[v] && !used[i]) {
                v = i;
            }
        }
        used[v] = 1;
        for (int i = 1; i <= n; i++) {
            if (!used[i] && di(a[v], a[i]) < dist[i]) {
                dist[i] = di(a[v], a[i]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        ans += sqrt(dist[i]);
    }
    cout << fixed << setprecision(6) << ans << '\n';
    
}