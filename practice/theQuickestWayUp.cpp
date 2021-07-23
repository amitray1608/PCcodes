
#include<bits/stdc++.h>

using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    vector<array<int, 2>> adj[106];
    for (int i = 0; i <= 99; i++) {
      for (int j = 1; j < 7; j++)
        adj[i].push_back({i + j, 1});
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      adj[u].push_back({v, 0});
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      adj[u].clear();
      adj[u].push_back({v, 0});
    }
    vector<int> dis(106, INT_MAX);
    minpq<array<int, 2>> pq;
    pq.push({0,0});
    dis[0] = 0;
    while (!pq.empty()) {
      auto [c, v] = pq.top();
      pq.pop();
      if (dis[v] < c) continue;
      for (auto i : adj[v]) {
        auto [u, w] = i;
        if (dis[v] + w < dis[u]) {
          dis[u] = dis[v] + w;
          pq.push({dis[u], u});
        }
      }
    }
    int mini = INT_MAX;
    for (int i = 99; i < 106; i++) {
      mini = min(mini, dis[i]);
    }
    cout << (mini == INT_MAX ? -1 : mini) << '\n';
  }	
  return 0;
}

