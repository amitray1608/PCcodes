#include<bits/stdc++.h>

using namespace std;

int dx[] = {1, 0, -1, 0}; int dy[] = {0, 1, 0, -1}; //4 Direction

int main() {
  
  int n, m;
  cin >> n >> m;
  string s[n];
  for(string &i : s) cin >> i;

  bool vis[n][m];
  memset(vis, 0, sizeof vis);

  queue<pair<int, int>> q;

  int ans = 0;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(vis[i][j] or s[i][j] == '0') continue;
      q.push({i, j});
      vis[i][j] = true;
      ans++;
      while(!q.empty()) {
        auto X = q.front();
        q.pop();
        for(int k = 0; k < 4; k++) {
          int x = X.first + dx[k], y = X.second + dy[k];
          if(x >= 0 and x < n and y >= 0 and y < m and !vis[x][y] and s[x][y] == '1') {
            vis[x][y] = 1;
            q.push({x, y});
          }
        }
      }
    }
  }

  cout << ans << '\n';
  return 0;
}
