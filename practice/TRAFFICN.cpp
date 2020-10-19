//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll siz = 1e6 + 5;
const ll MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

const ll inf = 1e18;
ll n, m, k, s, t;
vector<ll> dijk(int ss, vector<vector<array<ll, 3>>> &adj) {
  vector<ll>dis;
  dis.assign(n, inf);
  dis[ss] = 0;
  priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>>q;
  q.push({0, ss, 0});
  while(!q.empty()) {
    auto x = q.top();
    q.pop();
    ll u = x[1], w = x[0], type = x[2];
    //cout << u << ' ';
    if(w == inf) continue;
    for(auto i : adj[u]) {
      if(dis[i[0]] > dis[u]+i[1]) {
        dis[i[0]] = dis[u]+i[1];
        q.push({dis[i[0]], i[0], (type or i[2])});
      } 
    }
  }
  return dis;
}

void solve(){
  cin >> n >> m >> k >> s >> t;
  s--, t--;
  vector<vector<array<ll, 3>>>adj, adj2;
  adj.resize(n);
  adj2.resize(n);
  for(ll i = 0; i < m; i++) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    adj[u].push_back({v, w, 0});
    adj2[v].push_back({u, w, 0});
  
  }
  vector<ll>diss, dist;
  diss = dijk(s, adj);
  dist = dijk(t, adj2);
  ll mini = diss[t];
  for(ll i = 0; i < k; i++) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    mini = min(mini, min(diss[u]+w+dist[v], diss[v]+w+dist[u]));
  }
  if(mini >= inf) cout << -1 << endl;
  else
    cout << mini << endl;
  for(int i = 0; i < n; i++)
    adj[i].clear();
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1, tt = 0;
		cin >> t;
		while(t--){
			//tt++;
			//cout << "Case #" << t << ": ";
			solve();
		}
	return 0;
}
