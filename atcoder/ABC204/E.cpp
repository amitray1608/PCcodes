
#include<bits/stdc++.h>

using namespace std;

using ll = long long;
int n, m;
vector<ll> dist;
vector<vector<array<ll, 3>>> adj;
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
const ll inf = (ll) (1e18);
ll res = inf;

bool dijkstra(ll S, ll curr) {
  ll u , vv , c , w;
  minpq<array<ll, 3>> Q;
  fill(dist.begin(), dist.end(), inf);
  Q.push({curr, curr, S});
  dist[S] = curr;
  while(!Q.empty()){
    u = Q.top()[2];
    c = Q.top()[0];
    ll t = Q.top()[1];
    Q.pop();
    if(dist[u] < c){
      continue;
    }
    for(auto i : adj[u]){
      w = i[1] +  (i[2] / (t + 1LL));
      vv = i[0];
      if(dist[vv] > dist[u] + w){
        dist[vv] = dist[u] + w;
        Q.push({dist[vv], dist[vv], vv});
      }
    }
  }
  if (res >= dist[n - 1]) {
    res = dist[n - 1];
    return true;
  }
  return false;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  cin >> n >> m;
  adj.resize(n);
  dist.resize(n);
  for (int i = 0; i < m; i++) {
    ll u, v, c, d;
    cin >> u >> v >> c >> d;
    u--, v--;
    adj[u].push_back({v, c, d});
    adj[v].push_back({u, c, d});
  }
  
  ll l = 0LL, r = 1e18;
  while (l <= r) {
    ll mid = l + (r - l) / 2LL;
    if (dijkstra(0, mid)) {
      r = mid - 1LL;
    } else {
      l = mid + 1LL;
    }
  }
  cout << (res == inf ? -1 : res) << '\n';
  return 0;
} //Hajimemashite

