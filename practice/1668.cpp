#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> ans;
bool cycle = false;

int main() {
  cin >> n >> m;
  ans.resize(n, -1);
  adj.resize(n);
  vis.resize(n, false);
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v; u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  queue<pair<int, int>> q;
  for(int i = 0; i < n; i++) {
    if(vis[i]) continue;
    ans[i] = 0;
    q.push({i, 0});
    vis[i] = true;
    while(!q.empty()) {
      auto[u, t] = q.front();
      q.pop();
      for(int v : adj[u]) {
        if(!vis[v]) {
          ans[v] = t^1;
          vis[v] = true;
          q.push({v, t^1});
        } else if(ans[v] == t) cycle = true;
      }
    }
  }
  
  if(cycle) {
    cout << "IMPOSSIBLE\n";
  } else {
    for(int i = 0; i < n; i++) cout << ans[i] + 1 << ' ';
    cout << endl;
  }

  return 0;
}
