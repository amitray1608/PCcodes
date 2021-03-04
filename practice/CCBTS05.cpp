#include <bits/stdc++.h>

using namespace std;
#define int int64_t

const int MAXN = 1e5 + 1;
int tin[MAXN], tout[MAXN], dp[MAXN][20], level[MAXN], timer;
vector<pair<int, int>> adj[MAXN];
vector<int> dis(MAXN); 

void dfs(int u, int p, int l) {
  tin[u] = ++timer;
  level[u] = l;
  dp[u][0] = p;
  for(int i = 1; i <= 18; i++) 
    dp[u][i] = dp[dp[u][i - 1]][i - 1];
  for(auto v : adj[u])
    if(v.first != p) 
      dfs(v.first, u, l + v.second);
  tout[u] = ++timer;
}
 
bool is_ancestor(int u, int v) {
  return tin[u] <= tin[v] and tout[u] >= tout[v];
}
 
int lca(int u, int v) {
  if(is_ancestor(u, v)) return u;
  if(is_ancestor(v, u)) return v;
  for(int i = 18; i >= 0; i--) 
    if(!is_ancestor(dp[u][i], v))
      u = dp[u][i];
  return dp[u][0];
}
 
int dist(int u, int v) {
  return level[u] + level[v] - (level[lca(u, v)] << 1);
}



void solve() {
  memset(tin, 0, sizeof tin);
  memset(tout, 0, sizeof tout);
  memset(level, 0, sizeof level);
  int n, q, r;
  cin >> n >> q >> r;
  for (int i = 0; i < n; i++) {
    adj[i].clear();
    dis[i] = 0;
    for (int j = 0; j <= 19; j++) dp[i][j] = 0; 
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  dfs(r - 1, r - 1, 0); 
  while (q--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    cout << dist(u, v) << '\n';
  }
}

signed main() {
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


