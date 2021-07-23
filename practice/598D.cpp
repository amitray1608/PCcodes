
#include<bits/stdc++.h>

using namespace std;

int dx[] = {1, 0, -1, 0}; int dy[] = {0, 1, 0, -1};


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int n, m, q;
  cin >> n >> m >> q;
  vector<string> s(n);
  
  for (auto &i : s) {
    cin >> i;
  }
  map<pair<int, int>, pair<int, int>> p;
  map<pair<int, int>, int> res;

  vector<vector<bool>> vis;
  vis.resize(n, vector<bool>(m, 0));


  auto valid = [&](int i, int j) {
    if (i < 0 or i >= n or j < 0 or j >= m or vis[i][j])
      return false;
    return true;
  };

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vis[i][j] or s[i][j] == '*') {
        continue;
      }
      queue<pair<int, int>> q;
      q.push({i, j});
      p[{i, j}] = {i, j};
      vis[i][j] = true;
      while (!q.empty()) {
        auto x = q.front();
        int u = x.first;
        int v = x.second;
        q.pop();
        auto parent = p[x];
        for (int k = 0; k < 4; k++) {
          int newu = dx[k] + u;
          int newv = dy[k] + v;
          if (valid(newu, newv)) {
            if (s[newu][newv] == '.') {
              p[{newu, newv}] = parent; 
              q.push({newu, newv});
              vis[newu][newv] = true;
            } else {
              res[parent]++;
            }
          } 
        }
      }
    }
  }
  
  while (q--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    auto parent = p[{u, v}];
    cout << res[parent] << '\n';
  }


  return 0;
} //Hajimemashite

