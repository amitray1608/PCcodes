#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const ll MOD = 1e9 + 7;

const ll INF = 1e9;
typedef pair<ll, ll> pri;
vector<vector<pri>>adj;
vector<ll>dis, a;
ll n, m;

void dijk() {
  priority_queue<pri, vector<pri>, greater<pri>>q;
  for (ll i = 0; i < n; i++) {
    dis[i] = a[i];
    q.push({a[i], i});
  }
  while(!q.empty()) {
    auto x = q.top();
    q.pop();
    ll u = x.second;
    if(x.first != dis[u]) continue;
    for(auto i : adj[u]) {
      ll v = i.first;
      ll c = i.second;
      if(dis[v] > dis[u]+c) {
        dis[v] = dis[u]+c;
        q.push({dis[v], v});
      }
    }
  }
}

void solve(){
  cin >> n >> m;
  adj.resize(n);
  a.resize(n);
  dis.resize(n);
  for (ll i = 0; i < m; i++) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--, v--, w *= 2;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  for(ll &i : a) cin >> i;
  dijk();
  for(ll i = 0; i < n; i++) cout << dis[i] << ' ';
  cout << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
  //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
}//Hajimemashite

