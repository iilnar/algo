#include <fstream>

using namespace std;

ifstream cin ("pathsg.in");
ofstream cout ("pathsg.out");


int a[201][201];

const int maxx = 1e9;


int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            a[i][j] = maxx;
        }
    }
    for(int i = 0; i < m; i++) {
        int from, to, w;
        cin >> from >> to >> w;
        a[from][to] = w;
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }     
    return 0;
}    