#include <bits/stdc++.h>

using namespace std;

#define FILENAME "huffman"

vector <int> a, b;
const int INF = 1e8;
int n, i, j, ans;

int main () {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n;
    a.resize(n + 1, INF);
    b.resize(n, INF);
    for (int k = 0; k < n; k++) {
        cin >> a[k];
    }

    for (int k = 0; k < n - 1; k++) {
        if (a[i] + a[i + 1] <= a[i] + b[j] && a[i] + a[i + 1] <= b[j] + b[j + 1]) {
            b[k] = a[i] + a[i + 1];
            ans += b[k];
            i += 2;    
            continue;
        }
        if (a[i] + b[j] <= a[i] + a[i + 1] && a[i] + b[j] <= b[j] + b[j + 1]) {
            b[k] = a[i] + b[j];
            ans += b[k];
            i++;
            j++;
            continue;
        }
        if (b[j] + b[j + 1] <= a[i] + a[i + 1] && b[j] + b[j + 1] <= a[i] + b[j]) {
            b[k] = b[j] + b[j + 1];
            ans += b[k];
            j += 2;            
        }
    }
    cout << ans << "\n";
}