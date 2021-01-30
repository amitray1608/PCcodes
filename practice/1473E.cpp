
#include <bits/stdc++.h>

using namespace std;

#define int int64_t

struct Node {
  int w, maxi, mini, total;
};

vector<Node> dis;
vector<vector<pair<int, int>>> adj;

template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
const int inf = (int) (1e17);


void dijkstra(int S) {
  int u, c;
  minpq<pair<int, int>> Q;
  Q.push({0,S});
  dis[S].w = 0;
  while(!Q.empty()){
    u = Q.top().second;
    c = Q.top().first;
    Q.pop();
//    cout << u << '\n';
//    if(dis[u].w < c) continue;
    for(auto i : adj[u]) {
      int v = i.first;
      int w = i.second;
      int total = dis[u].total + w;
      int maxi = max(w, dis[u].maxi);
      int mini = min(w, dis[u].mini);
      if(dis[v].w > total - maxi + mini) {
        dis[v].w = total - maxi + mini;
        dis[v].total = total;
        dis[v].mini = mini;
        dis[v].maxi = maxi;
        Q.push({dis[v].w, v});
      }
    }
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  adj.resize(n);
  for(int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  dis.resize(n);
  for(int i = 0; i < n; i++) {
    dis[i].w = inf, dis[i].mini = inf, dis[i].maxi = 0, dis[i].total = 0;
  }
  dijkstra(0);
  for (int i = 1; i < n; i++) {
    cout << dis[i].w << ' ';
  } 
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  //cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite

