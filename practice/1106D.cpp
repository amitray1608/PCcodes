
#include <bits/stdc++.h>

using namespace std;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
  int n, m;
  cin >> n >> m;
  
  vector<bool> vis(n, 0);
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 0; i < n; i++) 
    sort(adj[i].begin(), adj[i].end());

  minpq<int> pq;
  pq.push(0);
  vis[0] = 1;
  while (!pq.empty()) {
    int s = pq.top();
    pq.pop();
    cout << s + 1 << ' ';
    for (int i : adj[s]) {
      if (!vis[i]) {
        pq.push(i);
        vis[i] = true;
      }
    }
  }
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


