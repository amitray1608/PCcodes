#include<bits/stdc++.h>

using namespace std;
const int maxn = 2005;
using ll = long long;

vector<pair<ll, ll>> G[maxn];
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
const ll inf = (ll) (1e18);
int n, m;

void dijkstra(int S) {
  ll u , vv , c , w;
  minpq<pair<ll, ll>> Q;
  vector<ll> dist(n);
  fill(dist.begin(), dist.end(), inf);
  Q.push({0,S});
//  dist[S] = 0;
  while(!Q.empty()){
    u = Q.top().second;
    c = Q.top().first;
    Q.pop();
    if(dist[u] < c){
      continue;
    }
    for(int i = 0 ; i < (int) G[u].size() ; i++){
      vv = G[u][i].first;
      w = G[u][i].second;
      if(dist[vv] > c + w){
        dist[vv] = c + w;
        Q.push({dist[vv],vv});
      }
    }
  }
  if (dist[S] == inf)  cout << -1 << '\n';
  else cout << dist[S] << '\n';
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    ll u, v, c;
    cin >> u >> v >> c;
    u--, v--;
    G[u].push_back({v, c});
  }
  
  for (int i = 0; i < n; i++) 
    dijkstra(i);

  return 0;
} //Hajimemashite
