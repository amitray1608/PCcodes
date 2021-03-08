
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
vector<ll> dist;
vector<vector<pair<ll, ll>>> adj;
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
const ll inf = (ll) (1e18);
ll n, k;

ll dijkstra(ll S) {
  ll u , vv , c , w;
  minpq<array<ll, 3>> Q;
  fill(dist.begin(), dist.end(), inf);
  Q.push({0, S, 0});
  dist[S] = 0;
  vector<ll> par(n + 1, 0);

  while(!Q.empty()) {
    u = Q.top()[1];
    c = Q.top()[0];
    ll kth = Q.top()[2];
    Q.pop();
    if(dist[u] < c or kth >= n - k){
      continue;
    }
    for(auto i : adj[u]){
      w = i.second;
      vv = i.first;
      if(dist[vv] > dist[u] + w and par[vv] < kth){
        dist[vv] = dist[u] + w;
        Q.push({dist[vv], vv, kth + 1});
      }
    }
  }

  ll mini = inf;
  for (int i = 0; i <= n; i++) {
    cout << dist[i] << ' ';
  }
  cout << '\n';
  for (int i = 1; i <= n; i++) {
    if (par[i] >= n - k) 
      mini = min(mini, dist[i]);
  }
  return mini;
}



void solve() {
  cin >> n >> k;
  
  vector<array<ll, 2>> a(n + 1);
  dist.resize(n + 1, 0);
  a[0][0] = a[0][1] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i][0] >> a[i][1];
  }
  
  adj.resize(n);
  for (ll i = 0; i < n; i++) {
    for (ll j = i + 1; j <= n; j++) {
      ll dis = abs(a[i][0] - a[j][0]) + abs(a[i][1] - a[j][1]);
      adj[i].push_back({j, dis});
    }
  }
  ll res = dijkstra(0);
  for (int i = 0; i <= n; i++) {
    adj[i].clear();
  }
  dist.clear();
  cout << res << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


