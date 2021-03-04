
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
const ll inf = (ll) (1e18);
vector<ll> dist;
vector<vector<array<ll, 3>>> adj;

void dijkstra(int S) {
  ll u , vv , c , w;
  minpq<pair<ll, ll>> Q;
  fill(dist.begin(), dist.end(), inf);
  Q.push({0,S});
  dist[S] = 0;

  while(!Q.empty()){
    u = Q.top().second;
    c = Q.top().first;
    Q.pop();
    if(dist[u] < c){
      continue;
    }
//  cout << "OK" << endl;
//  return;
    for(auto &i : adj[u]){
      w = i[1];
      vv = i[0];
      ll kth = i[2];
      if (c % kth != 0) {
        w += (kth * ((c / kth) + 1) - c);
      }
      if(dist[vv] > dist[u] + w){
        dist[vv] = dist[u] + w;
        Q.push({dist[vv],vv});
      }
    }
  }
}


void solve() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  x--, y--;
  adj.resize(n);
  dist.resize(n);
  for (int i = 0; i < m; i++) {
    int u, v, w, t;
    cin >> u >> v >> w >> t;
    u--, v--;
    adj[u].push_back({v, w, t});
    adj[v].push_back({u, w, t});
  }

  dijkstra(x);
  cout << (dist[y] >= inf ? -1 : dist[y]) << '\n';
}

int main() {
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



