#include <bits/stdc++.h>

using namespace std;

#define FILENAME "nextmultiperm"

int n;
vector <int> a;

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

int main () {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a = nextperm(a);
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
}
