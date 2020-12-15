#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
bool vis[MAXN];

void dfs(int s, vector<vector<int>> &adj) {
  vis[s] = true;
  for(auto v : adj[s])
    if(!vis[v])
      dfs(v, adj);
}


int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v; u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  memset(vis, 0, sizeof vis);
  int count = 0;
  vector<int> left;
  for(int i = 0; i < n; i++) {
    if(!vis[i]) {
      left.push_back(i);
      count++;
      dfs(i, adj);
    }
  }

  cout << count - 1 << '\n';
  for(int i = 1; i < (left.size()); i++)
    cout << left[i] + 1 << ' ' << left[i - 1] + 1 << '\n';

  return 0;
}
