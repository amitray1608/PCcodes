
#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<bool> vis;
long res;

void dfs(int s) {
  res++;
  vis[s] = true;
  for (int i : adj[s]) {
    if (!vis[i]) dfs(i);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  cin >> n >> m;
  adj.resize(n);
  vis.resize(n, false);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
  }
  for (int i = 0; i < n; i++) {
    vis.assign(n, false);
    dfs(i);
  }
  cout << res << '\n';
  return 0;
} //Hajimemashite

