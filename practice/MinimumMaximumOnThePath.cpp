//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const ll siz = 1e6 + 5;
const ll MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

ll n, m, d, inf = 1e9;
vector<vector<pair<ll, ll>>> adj;
vector<ll> path;

bool dfs(ll s, ll edg, ll dep) {
  path.push_back(s);
  bool exist = false;
  for(auto i : adj[s]) {
    if(i.second <= edg) {
      exist = (exist or dfs(i.first, edg, dep+1));
      if(exist) break;
    }
  }
  exist = (exist or (dep <= d and s == n-1)); 
  if(!exist) path.pop_back();
  return exist;
}

void solve() {
  cin >> n >> m >> d;
  adj.resize(n);
  for(ll i = 0; i < m; i++) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    adj[u].push_back({v, w});
  }

  auto check = [&](ll x) {
    path.clear();
    return dfs(0, x, 0);
  };

  ll l = 0, h = inf;
  while(l <= h) {
    ll mid = l+(h-l) / 2;
    if(check(mid)){
      h = mid - 1;
    } else
      l = mid + 1;
  }
  path.clear();
  bool flag = dfs(0, l, 0);
  if(!flag)
    cout << -1 << endl;
  else {
    cout << path.size() - 1 << endl;
    for(auto i : path)
      cout << i+1 << ' ';
    cout << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  ll t = 1;
  // cin >> t;
  for(ll tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  

