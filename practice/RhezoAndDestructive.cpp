
#include<bits/stdc++.h>

using namespace std;
int n, m;
vector<vector<int>> adj;
vector<int> vis, arti, tin, low;
int timer = 0;

void dfs(int s, int p = -1) {
  vis[s] = true;
  tin[s] = low[s] = timer++;
  int count = 0;
  for (int i : adj[s]) {
    if (i == p) continue;
    if (vis[i]) {
      low[s] = min(low[s], tin[i]);
    } else {
      dfs(i, s);
      low[s] = min(low[s], low[i]);
      if (low[i] >= tin[s] and p != -1) {
        arti[s] = true;
      }
      count++;
    }
  }
  if (p == -1 and count > 1) 
    arti[s] = true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  cin >> n >> m;
  adj.resize(n);
  vis.resize(n, 0);
  arti.resize(n, 0);
  tin.resize(n, 0);
  low.resize(n, INT_MAX);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  for (int i = 0; i < n; i++) {
    if (!vis[i]) dfs(i);
  }
  int q; cin >> q;
  while (q--) {
    int x;
    cin >> x;
    x--;
    if (arti[x]) {
      cout << "Satisfied" << ' ' << adj[x].size() << '\n';
    } else {
      cout << "Not Satisfied" << '\n';
    }
  }
  return 0;
} //Hajimemashite

