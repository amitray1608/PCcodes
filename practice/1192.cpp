#include<bits/stdc++.h>

using namespace std;
int dx[] = {1, 0, -1, 0}; int dy[] = {0, 1, 0, -1}; //4 Direction

int main() {
  int n, m;
  cin >> n >> m;
  string s[n];
  for(int i = 0; i < n; i++) cin >> s[i];
  vector<vector<bool>> vis(n, vector<bool>(m, false));
  int count = 0;

  auto valid = [&](int u, int v) {
    return (u < n and v < m and u >= 0 and  v >= 0 and s[u][v] == '.' and !vis[u][v]);
  };

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(vis[i][j] or s[i][j] == '#') continue;
      queue<pair<int, int>> q;
      q.push({i, j});
      vis[i][j] = true;
//      cout << i << ' ' << j << endl; 
      count++;
      while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for(int k = 0; k < 4; k++) {
          int u = x + dx[k], v = y + dy[k];
          if(valid(u, v)) {
            vis[u][v] = true;
            q.push({u, v});
          }
        }
      }
    }
  }

  cout << count << '\n';
  
  return 0;
}
