#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<int> val, maxsofar;
vector<vector<int>> adj;
vector<bool> vis;

int ans = INT_MIN;

void dfs(int s) {
  vis[s] = true;
  if(maxsofar[s] != -1) return;
  maxsofar[s] = 0;
  for(int &i : adj[s]) {
    dfs(i), maxsofar[s] = max(maxsofar[s], maxsofar[i]);
  }
  if(adj[s].size() != 0)
    ans = max(ans, maxsofar[s] - val[s]);
  maxsofar[s] = max(maxsofar[s], val[s]);
}

void solve() {
  int n, m;
  cin >> n >> m;
  val.resize(n);
  vis.resize(n, false);
  maxsofar.resize(n, -1);
  adj.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> val[i];
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
  }
  for(int i = 0; i < n; i++) {
    if(!vis[i]) dfs(i);
  }
//  for (int i = 0; i < n; i++) {
//    cout << maxsofar[i] << ' ';
//  } 
//  cout << '\n';
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  //cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite

