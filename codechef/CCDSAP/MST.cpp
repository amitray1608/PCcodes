//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const ll siz = 1e6 + 5;
const ll MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

const ll INF = 1e18;
vector<vector<ll>>adj;
vector<ll>vis;

struct Edge {
  ll w = INF, to = -1;
};
vector<Edge>mini;

void solve(){
  ll n, m;
  cin >> n >> m;
  adj.resize(n, vector<ll>(n, INF));
  vis.resize(n, false);
  for(ll i = 0; i < m; i++) {
    ll u, v, c;
    cin >> u >> v >> c;
    u--, v--;
    adj[u][v] = c;
    adj[v][u] = c;
  }
  ll ans = 0;
  mini.resize(n);
  mini[0].w = 0;
  for(ll i = 0; i < n; i++) {
    ll v = -1;
    for(ll j = 0; j < n; j++) {
      if(!vis[j] and (v == -1 or mini[j].w < mini[v].w))
          v = j;
    }
    if(mini[v].w == INF or v == -1) {
      cout << "IMPOSSIBLE" << endl;
      return;
    }
    vis[v] = true;
    ans = ans + mini[v].w;

    for(ll t = 0; t < n; t++) {
      if(adj[v][t] < mini[t].w) {
        mini[t].w = adj[v][t];
        mini[t].to = v;
      }
    }
  }
  cout << ans << endl;
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
