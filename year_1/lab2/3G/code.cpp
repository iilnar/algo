#include <bits/stdc++.h>

using namespace std;

#define FILENAME "nextpartition"

char c;
int k, n;
vector <int> a;

vector <int> nextpartition (vector <int> a) {
    if (a.size() == 1) {
        a[0] = -1;
        return a;
    }
    a[a.size() - 2]++;
    a[a.size() - 1]--;
    if (a[a.size() - 2] > a[a.size() - 1]) {
        a[a.size() - 2] += a[a.size() - 1];
        a.resize(a.size() - 1);
        return a;
    }
    while (a[a.size() - 2] * 2 <= a[a.size() - 1]) {
        a.push_back(a[a.size() - 1] - a[a.size() - 2]);
        a[a.size() - 2] = a[a.size() - 2] - a[a.size() - 1];
    }
    return a;
}

int main () {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n;
    while (cin >> c >> k) {
        a.push_back(k);
    }
    a = nextpartition(a);
    if (a[0] == -1) {
        cout << "No solution";
    } else {
        cout << n << '=' << a[0];
        for (int i = 1; i < a.size(); i++) {
            cout << '+' << a[i];
        }
    }

}
