#include <bits/stdc++.h>

using namespace std;

#define FILENAME "kth"

int n, k, A, B, C, a[30000001];

void partition(int &l, int &r) {
    int x = a[(l + r) / 2];
    for(;l <= r;) {
        while (a[l] < x) {
            l++;
        }
        while (a[r] > x) {
            r--;
        }
        if (l <= r) {
            swap(a[l], a[r]);
            l++;
            r--;
        }
       }
}


int kth(int l, int r, int k) {
    if (r - l == 1) {
        return a[l];
    }
    int i = l;
    int j = r - 1;
    partition(i, j);
    if (j - l + 1 < k && k < i - l + 1) {
        return a[j + k - (j - l + 1)];
    }
    if (k <= j - l + 1) {
        return kth(l, j + 1, k);
    } else {
        return kth(i, r, k - (i - l));
    }
}

int main() {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    cin >> n >> k >> A >> B >> C >> a[0] >> a[1];
    for (int i = 2; i < n; i++) {
        a[i] = A * a[i - 2] + B * a[i - 1] + C;
    }
    cout << kth(0, n, k);
}
