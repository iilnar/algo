#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream cin ("pathbge1.in");
ofstream cout ("pathbge1.out");


const int sz = 3e4 + 1;


int dis[sz];

vector < vector <int> > vv;


void bfs(int v) {
    dis[1] = 1;
    queue<int> q;
    q.push(v);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int i = 0; i < (int)vv[now].size(); i++) {
            int to = vv[now][i];
            if(dis[to] == 0) {
                dis[to] = dis[now] + 1;
                q.push(to);
            }
        }
    }
}    



int main() {
    int n, m;
    cin >> n >> m;
    vv.resize(n + 1);
    for(int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        vv[from].push_back(to);
        vv[to].push_back(from);
    }
    bfs(1);
    for(int i = 1; i <= n; i++) {
        cout << dis[i] - 1 << ' ';
    }
    cout << '\n';     
    return 0;
}    