#include <fstream>
#include <vector>
#include <cstdio>

#define FILENAME "o2cmax"

using namespace std;

struct job {
    int id, first, second;
};

int main() {
    freopen(FILENAME".in", "r", stdin); freopen(FILENAME".out", "w", stdout);
    int n;
    scanf("%d", &n);
    vector <job> a(n);
    vector <int> I, J;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].first);
        a[i].id = i;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].second);
    }
    int x = -1, y = -1;
    long long sumFirst = 0, sumSecond = 0, c = 0;
    for (int i = 0; i < n; i++) {
        sumFirst += a[i].first;
        sumSecond += a[i].second;
        c = max(c, 0LL + a[i].first + a[i].second);
        if (a[i].first <= a[i].second) {
            I.push_back(i);
            if (x == -1 || a[x].first < a[i].first) {
                x = i;
            }
        } else {
            J.push_back(i);
            if (y == -1 || a[y].second < a[i].second) {
                y = i;
            }
        }
    }
    c = max(c, max(sumFirst, sumSecond));
    vector <pair <long long, long long> > ans(n);
    bool swapped = false;
    if (x == -1 || (y != -1 && a[x].first <= a[y].second)) {
        swapped = true;
        swap(I, J);
        swap(x, y);
        for (int i = 0; i < n; i++) {
            swap(a[i].first, a[i].second);
        }
    }
    long long t1 = 0, t2 = 0;
    for (int i = 0; i < I.size(); i++) {
        if (I[i] != x) {
            ans[I[i]].first = t1;
            t1 += a[I[i]].first;
        }
    }
    ans[x].second = 0;
    t2 = a[x].second;
    for (int i = 0; i < I.size(); i++) {
        if (I[i] != x) {
            ans[I[i]].second = t2;
            t2 += a[I[i]].second;
        }
    }
    t1 = c;
    t1 -= a[x].first;
    ans[x].first = t1;
    for (int i = 0; i < J.size(); i++) {
        t1 -= a[J[i]].first;
        ans[J[i]].first = t1;
    }
    t2 = c;
    for (int i = 0; i < J.size(); i++) {
        t2 -= a[J[i]].second;
        ans[J[i]].second = t2;
    }
    printf("%lld\n", c);
    for (int i = 0; i < n; i++) {
        printf("%lld ", (!swapped ? ans[i].first : ans[i].second));
    }
    printf("\n");
    for (int j = 0; j < n; j++) {
        printf("%lld ", (!swapped ? ans[j].second : ans[j].first));
    }
    printf("\n");
}
