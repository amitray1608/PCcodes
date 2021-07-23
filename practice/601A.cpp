
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> bus, train;
  bus.resize(n, vector<int>(m, 1));
  train.resize(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    train[u].push_back(v);
    train[v].push_back(u);
    bus[u][v] = bus[v][u] = 0;
  }

  vector<bool> vis(n, 0);
  vis[0] = true;
  queue<pair<int, int>> q;
  q.push({0, 0});
  int miniBus = INT_MAX;
  while (!q.empty()) {
    auto s = q.front();
    int u = s.first;
    int c = s.second;
    q.pop();
    if (s.first == n - 1) {
      miniBus = c;
      break;
    }
    for (int i = 0; i < n; i++) {
      if (!vis[i] and bus[u][i]) {
        q.push({i, c + 1});
        vis[i] = true;
      }
    }
  }

  while (!q.empty()) {
    q.pop();
  }
  int miniTrain = INT_MAX;
  q.push({0, 0});
  vis.assign(n, 0);
  vis[0] = true;
  while (!q.empty()) {
    auto s = q.front();
    int u = s.first;
    int c = s.second;
    q.pop();
    if (s.first == n - 1) {
      miniTrain = c;
      break;
    }
    for (int i : train[u]) {
      if (!vis[i]) {
        q.push({i, c + 1});
        vis[i] = true;
      }
    }
  }

  bool ok = (miniTrain == INT_MAX);
  ok |= (miniBus == INT_MAX);
  if (ok) {
    cout << -1 << '\n';
  } else {
    cout << max(miniTrain, miniBus) << '\n';
  }

  return 0;
} //Hajimemashite

