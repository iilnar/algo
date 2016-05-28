#include <bits/stdc++.h>

using namespace std;

#define FILENAME "nextperm"

int n;
vector <int> a, b, c;
vector <int> nextperm (vector <int> a) {
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] < a[i + 1]) {
            int pos = i + 1;
            for (int j = i + 1; j < n; j++) {
                if (a[i] < a[j] && a[j] < a[pos]) {
                    pos = j;
                }
            }
            swap(a[i], a[pos]);
            sort(a.begin() + i + 1, a.end());
            return a;
        }
    } 
    for (int i = 0; i < n; i++) {
        a[i] = 0;
    }
    return a;     
}              

vector <int> prevperm (vector <int> a) {
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] > a[i + 1]) {
            int pos = i + 1;
            for (int j = i + 1; j < n; j++) {
                if (a[pos] < a[j] && a[j] < a[i]) {
                    pos = j;
                }
            }
            swap(a[i], a[pos]);
            sort(a.begin() + i + 1, a.end());
            reverse(a.begin() + i + 1, a.end());
            return a;

        }
    }
    for (int i = 0; i < n; i++) {
        a[i] = 0;
    }
    return a;
}

int main () {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    c = nextperm(a);
    b = prevperm(a);
    for (int i = 0; i < n; i++) {
        cout << b[i] << ' ';
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << c[i] << ' ';
    }
}