#include <bits/stdc++.h>

using namespace std;

#define FILENAME "nextchoose"

int n, k, arr[100001];

int main () {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME"ARINA.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> arr[i];
    }
    if (arr[k] < n) {
        arr[k]++;
    } else {
        bool luck = false;
        for (int i = k - 1; i >= 1; i--) {
            if (arr[i] + 1 < arr[i + 1]) {
                int p = arr[i] + 1;
                for (int j = i; j <= k; j++) {
                    arr[j] = p + j - i;
                }
                luck = true;
                break;
            }
        }
        if (!luck) {
            cout << -1;
            return 0;
        }
    }
    for (int i = 1; i <= k; i++) {
        cout << arr[i] << ' ';
    }

}