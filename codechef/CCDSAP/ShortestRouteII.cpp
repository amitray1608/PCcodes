//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

vector<vector<pair<int, int>>>adj;
vector<ll>dist;

void dijkstra(int s) {
  set<pair<ll, int>>q;
  q.insert({0, s});
  dist[s] = 0;
  while(!q.empty()) {
    int x = q.begin()->second;
    ll cs = q.begin()->first;
    q.erase(q.begin());
    if(cs != dist[x])
      continue;
    for(auto i : adj[x]) {
      int to = i.first;
      ll cos = i.second;
      if(dist[x] + cos < dist[to]){
        dist[to] = dist[x] + cos;
        q.insert({dist[to], to});
      }
    }
  }
}

vector<vector<ll>>dis;
void floyd(int n) {
  for(int i = 0; i < n; i++) {
    dis[i][i] = 0;
  }
  for(int k = 0; k < n; k++){
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(dis[i][k] < LONG_MAX && dis[k][j] < LONG_MAX)
          dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
}

void solve(){
  int n, m, q;
  cin >> n >> m >> q;
  dist.resize(n, LONG_MAX);
  adj.resize(n);
  dis.resize(n, vector<ll>(n, LONG_MAX));
  while(m--) {
    int u, v, c;
    cin >> u >> v >> c;
    u--;
    v--;
    adj[u].push_back({v, c});
    dis[u][v] = min((ll)c, dis[u][v]);
    dis[v][u] = min((ll)c, dis[v][u]);
  }
  // vector<vector<ll>> ans(n);
  // for(int i = 0; i < n; i++){
  //   dist.resize(n, LONG_MAX);
  //   dijkstra(i);
  //   ans[i] = dist;
  // }
  floyd(n);
  // for(int i = 0; i < n; i++){
  //   for(int j = 0; j < n; j++) {
  //     cout << dis[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
  while(q--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if(dis[u][v] >= LONG_MAX)
      cout << -1 << endl;
    else
      cout << dis[u][v] << endl;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  