#include <bits/stdc++.h>

using namespace std;

#define FILENAME "levenshtein"

string a, b;
vector <vector <int> > ans;

int main () {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    int deleteCost = 2, replaceCost = 7, insertCost = 2;
    cin >> deleteCost >> insertCost >> replaceCost;
    cin >> a >> b;
    a = "." + a;
    b = "." + b;
    ans.resize(a.size(), vector <int> (b.size()));
    for (int i = 0; i < b.size(); i++) {
        ans[0][i] = insertCost * i;
    }
    for (int i = 0; i < a.size(); i++) {
        ans[i][0] = deleteCost * i;
    }
    for (int i = 1; i < a.size(); i++) {
        for (int j = 1; j < b.size(); j++) {
            ans[i][j] = min(min(ans[i][j - 1] + insertCost, ans[i - 1][j] + deleteCost), ans[i - 1][j - 1] + replaceCost * (a[i] != b[j]));
            cout << ans[i][j] << ' ';
        }    
        cout << "\n";
    }
    cout << ans[a.size() - 1][b.size() - 1];
}