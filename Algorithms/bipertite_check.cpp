#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
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
  vector<int> side(n, -1);
  bool ok = true;
  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (side[i] != -1) continue;
    q.push(i);
    side[i] = 0;
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int u : adj[v]) {
        if (side[u] == -1) {
          side[u] = side[v] ^ 1;
          q.push(u);
        } else {
          ok &= side[u] != side[v];
        }
      }
    }
  }
  cout << (ok ? "YES" : "NO") << '\n';
  return 0;
} //Hajimemashite


