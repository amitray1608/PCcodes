#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const ll MOD = 1e9 + 7;
const ll inf = 1e9;

void solve() {
  ll n, m;
  cin >> n >> m;
  vector<vector<pair<ll, ll>>> adj(n);
  for(ll i = 0; i < m; i++) {
    ll u, v;
    cin >> u >> v; u--, v--;
    adj[u].push_back({v, 0});
    adj[v].push_back({u, 1});
  }
  deque<ll> q;
  vector<ll> dis(n, inf);
  dis[0] = 0;
  q.push_back(0);
  while(!q.empty()) {
    ll u = q.front();
    q.pop_front();
    for(auto i : adj[u]) {
      ll v = i.first, w = i.second;
      if(dis[u] + w < dis[v]) {
        dis[v] = dis[u] + w;
        ( w ? q.push_back(v) : q.push_front(v));
      }
    }
  }
  cout << (dis[n - 1] >= inf ? -1 : dis[n - 1]);
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  ll t = 1, tt = 0;
  //cin >> t;
  while(t--){
    //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite
