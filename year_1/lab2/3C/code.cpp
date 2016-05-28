#include <bits/stdc++.h>

using namespace std;

#define FILENAME "nextchoose"

vector <int> a;
int n, k;

vector <int> nextchoose (vector <int> a) {
    a.push_back(n + 1);
    for (int i = k - 1; i >= 0; i--) {
        if (a[i + 1] - a[i] >= 2) {
            a[i]++;
            for (int j = i + 1; j < k; j++) {
                a[j] = a[j - 1] + 1;
            }
            a.resize(k);
            return a;
        } 
    } 
    a.clear();
    a.push_back(-1);
    return a; 
}

int main () {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n >> k;
    a.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    a = nextchoose(a);
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << ' ';
    }
}