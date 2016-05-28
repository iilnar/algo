#include <bits/stdc++.h>

using namespace std;
#define FILENAME "garland"

int n;
double h0, ans = 10000000000000, mn;
const double EPS = 1e-9;
vector <double> h, rec;

vector <double> recover(double h0, double h1) {
    vector <double> res(n);
    res[0] = h0; res[1] = h1;
    for (int i = 2; i < n; i++) {
        res[i] = 2 * res[i - 1] + 2 - res[i - 2];
    }
    return res;
}

void print(vector <double> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';
}

int main() {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n >> h0;
    h.resize(n);
    double l = 0, r = 5000000000, m;
    while (abs(l - r) > EPS) {
        m = (l + r) / 2;
        double ll = 0, rr = 5000000000, mm;
        while (abs(ll - rr) > EPS) {
            mm = (ll + rr) / 2;
            rec = recover(h0, mm);
            if (abs(m - rec[n - 1]) <= EPS) {
                break;
            }
            if (rec[n - 1] < m) {
                ll = mm;
            } else {
                rr = mm;
            }
        }
//        cout << m << ' ' << mm << "\n";
        rec = recover(h0, mm);
//        print(rec);
        mn = min(rec[0], rec[n - 1]);
        for (int i = 0; i < n; i++) {
            mn = min(rec[i], mn);
        }
        if (mn > 0) {
            r = m;
            ans = min(ans, m);
        } else {
            l = m;
        }
    }
//    print(recover(15, 2500));
    cout << fixed << setprecision(10) << ans;
}
