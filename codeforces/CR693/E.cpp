#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;
vector<vector<pair<int, int>>> G;

template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
const ll inf = (ll) (1e18);
int n, m;

vector<ll> dijkstra(int S) {
  ll u , vv , c , w;
  minpq<pair<ll, ll>> Q;
  vector<ll> dist(n);
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
    for(int i = 0 ; i < (int) G[u].size() ; i++){
      w = G[u][i].first;
      vv = G[u][i].second;
      if(dist[vv] > dist[u] + w){
        dist[vv] = dist[u] + w;
        Q.push({dist[vv],vv});
      }
    }
  }
  return dist;
}

void solve() {
  cin >> n >> m;
  G.resize(n);
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v; u--, v--;
    G[u].push_back({1, v});
  }
  vector<ll>dist = dijkstra(0);
//  for(auto i : dist) cout << i << ' ';
//  cout << '\n';
  vector<ll> res(n, inf);
  function<void(ll)> dfs = [&](ll s) {
    res[s] = dist[s];
    for(auto u : G[s]) {
      int v = u.second;
      if(dist[v] > dist[s]) {
        if(res[v] == inf) {
          dfs(v);
          res[s] = min(res[s], res[v]);
        } else res[s] = min(res[s], res[v]);
      } else res[s] = min(dist[v], res[s]);
    }
  };

  dfs(0);
  for(auto i : res) cout << i << ' ';
  cout << '\n';
  
  for (int i = 0; i < n; i++) {
    G[i].clear();
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
    //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite
