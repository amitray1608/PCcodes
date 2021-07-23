
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v; u--, v--;
    adj[u].push_back(v);
  }

  auto calc = [&](int x, int y) {
    return (y - x + n) % n;
  };

  for (int i = 0; i < n; i++) {
    int maxi = 0;
    for (int j = 0; j < n; j++) {
      int mini = 1e9;
      for (int k : adj[j]) {
        int dist = calc(i, j) + calc(j, k);
        dist += (n * (adj[j].size() - 1));
        mini = min(dist, mini);
      }
      if (mini != 1e9)
        maxi = max(maxi, mini);
    }
    cout << maxi << ' ';
  }
  cout << '\n';
  return 0;
} //Hajimemashite

