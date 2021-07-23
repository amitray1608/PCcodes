
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> adj;
  adj.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  vector<int> order(n);
  for (int i = 0; i < n; i++) {
    sort (adj[i].begin(), adj[i].end());
    cin >> order[i];
    order[i]--;
  }

  queue<int>q;
  bool ok = true;
  int itr = 1;
  vector<bool> vis(n, 0);
  q.push(0);
  vis[0] = true;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    while (itr < n) {
      int x = order[itr];
      if (!vis[x] and binary_search(adj[u].begin(), adj[u].end(), x)) {
        q.push(x);
        vis[x] = true;
        itr++;
      } else break; 
    }
  }
  ok = (itr == n);
  cout << (ok ? "Yes" : "No") << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int t = 1;
  //cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


