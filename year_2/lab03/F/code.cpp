#include <fstream>
#include <vector>
#include <cstdlib>
#include <stack>
 
using namespace std;
 
ifstream cin ("negcycle.in");
ofstream cout ("negcycle.out");
 
 
typedef long long ll;
 
const ll maxx = (ll)1e9;
 
struct Edge {
    int from, to;
    ll w;
    Edge() {}
    Edge(int from, int to, ll w): from(from), to(to), w(w) {}
};
 
vector <Edge> v;
vector <int> f;
vector <vector <Edge> > vv;
 
 
int n, m, s;
 
 
void belman(vector <ll> &d) {
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < (int)v.size(); i++) {
            if (d[v[i].to] > d[v[i].from] + v[i].w) {
                d[v[i].to] = d[v[i].from] + v[i].w;            
                f[v[i].to] = v[i].from;
            }
        }
    }  
}   
 
     
int main() {
    cin >> n;
    vv.resize(n);
    f.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int c;
            cin >> c;
            if (c != maxx) {
                v.push_back(Edge(i, j, c));
                vv[i].push_back(Edge(i, j, c));
            }
        }
    }
    vector <ll> d1(n, 0);
    belman(d1);          
    vector <int> inCycle(n, 0);
    stack <int> q;
    for(int i = 0; i < (int)v.size(); i++) {
        if (d1[v[i].to] > d1[v[i].from] + v[i].w) {
            inCycle[v[i].to] = true;
        }
    }
    int v = -1;
    for (int i = 0; i < n; i++) {
        if (inCycle[i]) {
            v = i;
            break;
        }
    }
    if (v == -1) {
        cout << "NO\n";
        return 0;
    }
    for (int i = 0; i < n; i++) {
        v = f[v];
    }
    int t = f[v];
    q.push(v);
    while (t != v) {
        q.push(t);
        t = f[t];
    }
    q.push(v);
    cout << "YES\n" << q.size() << '\n';
    while (!q.empty()) {
        cout << q.top() + 1 << ' ';
        q.pop();
    }
    return 0;
}   