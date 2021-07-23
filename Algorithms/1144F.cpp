
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
  bool ok = true;
  vector<int> color(n, -1);
  for (int i = 0; i < n; i++) {
    if (color[i] != -1) continue;
    queue<int> q;
    q.push(i);
    color[i] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : adj[u]) {
        if (color[v] == -1) {
          color[v] = color[u] ^ 1;
          q.push(v);
        } else {
          ok &= color[u] != color[v];
        }
      }
    }
  }
  if (!ok) {
    cout << "NO" << '\n';
  } else {
    cout << "YES" << '\n';
    for (int i : color) {
      cout << i;
    } cout << '\n';
  }
  return 0;
} //Hajimemashite

