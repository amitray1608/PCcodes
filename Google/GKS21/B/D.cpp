
#include <bits/stdc++.h>

using namespace std;
#define int int64_t

void solve() {
  int n, q;
  cin >> n >> q;
  vector<vector<array<int, 3>>> adj(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v, l, a;
    cin >> u >> v >> l >> a;
    u--, v--;
    adj[u].push_back({v, l, a});
    adj[v].push_back({u, l, a});
  }
  vector<int> res;
  vector<bool>vis;
  function<void(int, int)> dfs = [&](int u, int w) {
    vis[u] = true;
    for (auto i : adj[u]) {
      if (!vis[i[0]]) {
        res[i[0]] = res[u];
        if (i[1] <= w) 
         res[i[0]]  = __gcd(i[2], res[u]);
        dfs(i[0], w);
      }
    }
  };

  while (q--) {
    res.assign(n, 0);
    vis.assign(n, false);
    int v, w;
    cin >> v >> w;
    v--;
    dfs(0, w);
    cout << res[v]  << ' ';
  }
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


