
#include<bits/stdc++.h>

using namespace std;
#define int int64_t
const int inf = 1e10;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>(n, inf));
  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    u--, v--;
    adj[u][v] = c; 
  }
  for (int i = 0; i < n; i++) adj[i][i] = 0;
  int sum = 0;
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (adj[i][k] < inf and adj[k][j] < inf)
          adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
        if(adj[i][j] < inf) sum += adj[i][j];
      }
    }
  }
  cout << sum << '\n';
  return 0;
} //Hajimemashite

