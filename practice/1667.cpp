#include<bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> adj[n];
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v; u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> par(n, -1);
  vector<bool> vis(n, false);
  queue<int> q;
  q.push(0);
  vis[0] = true;
  while(!q.empty()) {
    int x = q.front();
    q.pop();
    if(x == n - 1) {
      break;
    }
    for(int v : adj[x]) {
      if(!vis[v]) {
        par[v] = x;
        q.push(v);
        vis[v] = true;
      }
    }
  }
  if(par[n - 1] == -1) {
    cout << "IMPOSSIBLE" << '\n';
  } else {
    vector<int> ans;
    int x = n - 1;
    ans.push_back(n - 1);
    while(par[x] != -1) 
      ans.push_back(par[x]), x = par[x];
    reverse(ans.begin(), ans.end());
     cout << ans.size()  << '\n';
    for(int i : ans) cout << i + 1 << ' ';
  }
  return 0;
}
