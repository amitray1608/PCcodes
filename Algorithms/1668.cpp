
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    bool ok = true;
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++) {
      if (color[i] != -1) continue;
      queue<int> q;
      q.push(i);
      color[i] = 0;
      while (!q.empty()) {
        auto v = q.front();
        q.pop();
        for (int u : adj[v]) {
          if (color[u] == -1) {
            color[u] = color[v] ^ 1;
            q.push(u);
          } else {
            ok &= color[u] != color[v];
          }
        }
      }
    }
    cout << "Scenario #" << tt << ":" << '\n';
    if (ok) {
      cout << "No suspicious bugs found!" << '\n';
    } else {
      cout << "Suspicious bugs found!" << '\n';
    }
  }
  
  return 0;
} //Hajimemashite

