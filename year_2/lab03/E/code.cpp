#include <fstream>
#include <vector>
#include <cstdlib>
#include <queue>
 
using namespace std;
 
ifstream cin ("path.in");
ofstream cout ("path.out");
 
 
typedef long long ll;
 
const ll maxx = (ll)2e18 + 2;
 
struct Edge {
    int from, to;
    ll w;
    Edge() {}
    Edge(int from, int to, ll w): from(from), to(to), w(w) {}
};
 
vector <Edge> v;
vector <vector <Edge> > vv;
 
 
int n, m, s;
 
 
 
void belman(vector <ll> &d) {
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < (int)v.size(); i++) {
            if(d[v[i].from] == maxx) continue;
            d[v[i].to] = min(d[v[i].to], max(-maxx, d[v[i].from] + v[i].w));
        }
    }  
}   
 
     
int main() {
    cin >> n >> m >> s;
    vv.resize(n + 1);
    for(int i = 0; i < m; i++) {
        ll from, to, w;
        cin >> from >> to >> w;
        v.push_back(Edge(from, to, w));
        vv[from].push_back(Edge(from, to, w));
    }
    vector <ll> d1(n + 1, maxx);
    d1[s] = 0;
    belman(d1);          
    vector <int> inCycle(n + 1, 0);
    queue <int> q;
    for(int i = 0; i < (int)v.size(); i++) {
        if(d1[v[i].from] == maxx) continue;
        if (d1[v[i].to] > d1[v[i].from] + v[i].w) {
            inCycle[v[i].to] = true;
            q.push(v[i].to);
        }
    }
    while (!q.empty()) {
        int from = q.front();
        q.pop();
        for (int i = 0; i < vv[from].size(); i++) {
            if (inCycle[vv[from][i].to] == 0) {
                inCycle[vv[from][i].to] = true;
                q.push(vv[from][i].to);
            }
        }       
    }
    for(int i = 1; i <= n; i++) {
        if(inCycle[i]) {
            cout << "-\n";
            continue;
        }   
        if(d1[i] == maxx) {
            cout << "*\n";
            continue;
        }
        cout << d1[i] << '\n';
    }   
    return 0;
}   