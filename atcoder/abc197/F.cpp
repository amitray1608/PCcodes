
#include<bits/stdc++.h>

using namespace std;
const int inf = 1e7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<tuple<int, int, char>>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    char c;
    cin >> u >> v >> c;
//    if (u == v) continue;
    adj[--u].push_back({--v, 1, c});
    adj[v].push_back({u, 1, c});
  }
  int mini = inf;
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
  pq.push({0, 0, n - 1});
  vector<vector<int>> dis(n + 1, vector<int> (n + 1, inf));
  while (!pq.empty()) {
    auto xx = pq.top();
    pq.pop();
    int v = get<1>(xx);
    int u = get<2>(xx);
    int w = get<0>(xx);
    if (u == v) {
      mini = min(mini, w);
      continue;
    }
    for (auto x : adj[v]) {
      for (auto y : adj[u]) {
        if (get<0>(x) == u and get<0>(y) == v) 
          mini = min(mini, w + get<1>(x));
        else if (get<2>(x) == get<2>(y) and w + get<1>(x) + get<1>(y) < dis[get<0>(x)][get<0>(y)]) {
          dis[get<0>(x)][get<0>(y)] = w + get<1>(x) + get<1>(y);
          pq.push({w + get<1>(x) + get<1>(y), get<0>(x), get<0>(y)});
        }
      }
    }
  }
  cout << (mini ^ inf ? mini : -1) << '\n';
  return 0;
} //Hajimemashite

