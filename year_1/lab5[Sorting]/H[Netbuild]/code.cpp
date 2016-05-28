#include <bits/stdc++.h>

using namespace std;

#define FILENAME "netbuild"
#define x first
#define y second
#define mp make_pair
#define pb push_back

vector <vector <pair <int, int> > > a;
int n;

int main() {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n;
    a.resize(9);
    a[0].pb(mp(1, 2));a[0].pb(mp(3, 4));a[0].pb(mp(5, 6));a[0].pb(mp(7, 8));a[0].pb(mp(9, 10));a[0].pb(mp(11, 12));a[0].pb(mp(13, 14));a[0].pb(mp(15, 16));

    a[1].pb(mp(1, 3));a[1].pb(mp(2, 4));a[1].pb(mp(5, 7));a[1].pb(mp(6, 8));a[1].pb(mp(9, 11));a[1].pb(mp(10, 12));a[1].pb(mp(13, 15));a[1].pb(mp(14, 16));

    a[2].pb(mp(1, 5));a[2].pb(mp(2, 6));a[2].pb(mp(3, 7));a[2].pb(mp(4, 8));a[2].pb(mp(9, 13));a[2].pb(mp(10, 14));a[2].pb(mp(11, 15));a[2].pb(mp(12, 16));

    a[3].pb(mp(1, 9));a[3].pb(mp(2, 10));a[3].pb(mp(3, 11));a[3].pb(mp(4, 12));a[3].pb(mp(5, 13));a[3].pb(mp(6, 14));a[3].pb(mp(7, 15));a[3].pb(mp(8, 16));

    a[4].pb(mp(2, 3));a[4].pb(mp(4, 13));a[4].pb(mp(14, 15));a[4].pb(mp(5, 9));a[4].pb(mp(6, 11));a[4].pb(mp(7, 10));a[4].pb(mp(8, 12));

    a[5].pb(mp(2, 5));a[5].pb(mp(12, 15));a[5].pb(mp(3, 9));a[5].pb(mp(8, 14));a[5].pb(mp(4, 10));a[5].pb(mp(6, 13));a[5].pb(mp(7, 11));

    a[6].pb(mp(3, 5));a[6].pb(mp(4, 6));a[6].pb(mp(7, 9));a[6].pb(mp(8, 10));a[6].pb(mp(11, 13));a[6].pb(mp(12, 14));

    a[7].pb(mp(4, 7));a[7].pb(mp(6, 9));a[7].pb(mp(8, 11));a[7].pb(mp(10, 13));

    a[8].pb(mp(4, 5));a[8].pb(mp(6, 7));a[8].pb(mp(8, 9));a[8].pb(mp(10, 11));a[8].pb(mp(12, 13));

    int sum = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            if (a[i][j].x > n || a[i][j].y > n) {
                a[i].erase(a[i].begin() + j, a[i].begin() + j + 1);
                j--;
            }
        }
        sum += a[i].size();
        if (a[i].size() == 0) {
            a.erase(a.begin() + i, a.begin() + i + 1);
            i--;
        }
    }
    cout << n << ' ' << sum << ' ' << a.size() + 1 << "\n0" << '\n';
    for (int i = 0; i < a.size(); i++) {
        cout << a[i].size() << ' ';
        for (int j = 0; j < a[i].size(); j++) {
            cout << a[i][j].x << ' ' << a[i][j].y << ' ';
        }
        cout << '\n';
    }
}