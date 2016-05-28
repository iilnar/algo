#include <bits/stdc++.h>

using namespace std;
#define FILENAME "Damerau-Levenshtein"

string a, b;

int DamerauLevenshtein (string a, string b) {
    int n = a.size() - 1, m = b.size() - 1;
    cout << "N = " << n <<  " M = " << m << "\n";
    if (a == ".") {
        if (b == ".") {
            return 0;
        } else {
            return b.size() - 1;
        }
    } else {
        if (b == ".") {
            return a.size() - 1;
        }
    } 
    int INF = 1e9;
    vector <vector <int> > d(n + 2, vector <int> (m + 2, INF));
    d[0][0] = INF;
    for (int i = 0; i <= n; i++) {
        d[i + 1][1] = i;
        d[i + 1][0] = INF;
    }
    for (int i = 0; i <= m; i++) {
        d[1][i + 1] = i;
        d[0][i + 1] = INF;
    }
    vector <int> lastPosition(26, 0);
    for (int i = 1; i <= n; i++) {
        int last = 0;
        for (int j = 1; j <= m; j++) {
            int in = lastPosition[b[j] - 'A'];
            int jn = last;
            if (a[i] == b[j]) {
                d[i + 1][j + 1] = d[i][j];
                last = j;
            } else {
                d[i + 1][j + 1] = min(d[i][j], min(d[i + 1][j], d[i][j + 1])) + 1;
            }
//            cout << in << ' ' << jn << '\n';
//            cout << d[in][jn] + 1 + (i - in - 1) + (j - jn - 1) << "\n";
//            cout << d[in][jn] << "\n";
            d[i + 1][j + 1] = min(d[i + 1][j + 1], d[in][jn] + 1 + (i - in - 1) + (j - jn - 1)); 
//            cout << "d[" << i + 1 << "][" << j + 1 << "] = " << d[i + 1][j + 1] << "\n";
        }
        lastPosition[a[i] - 'A'] = i;
    }
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            cout << d[i][j] << ' ';
        }
        cout << "\n";
    }
    return d[n + 1][m + 1];
}

int main () {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> a >> b;
    cout << DamerauLevenshtein("." + a, "." + b) << "\n";
}