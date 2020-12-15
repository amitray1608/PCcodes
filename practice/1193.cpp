#include<bits/stdc++.h>

using namespace std;

int dx[] = {1, 0, -1, 0}; int dy[] = {0, 1, 0, -1}; //4 Direction

int main() {
  int n, m;
  cin >> n >> m;
  string s[n];
  for(string &i : s) cin >> i;
  
  vector<vector<bool>> vis(n, vector<bool>(m, false));
  vector<vector<pair<int, int>>> par(n, vector<pair<int, int>>(m, {-1, -1}));
  
  int x, y, xx, yy;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) 
      if(s[i][j] == 'A')
        x = i, y = j;
      else if(s[i][j] == 'B')
        xx = i, yy = j;

  queue<pair<int, int>> q;
  q.push({x, y});
  vis[x][y] = true;
  
  auto valid = [&](int u, int v) {
    return (u >= 0 and u < n and v >= 0 and v < m and !vis[u][v] and (s[u][v] == '.' or s[u][v] == 'B'));
  };

  while(!q.empty()) {
    tie(x, y) = q.front();
    if(x == xx and y == yy) {
      break;
    }
    q.pop();
    for(int i = 0; i < 4; i++) {
      int u = x + dx[i], v = y + dy[i];
      if(valid(u, v)) {
        q.push({u, v});
        par[u][v] = {x, y};
        vis[u][v] = true;
      }
    }
  }

//  for(int i = 0; i < n; i++) {
//    for(int j = 0; j < m; j++) cout << " {" << par[i][j].first << ',' << par[i][j].second << "} ";
//    cout << endl;
//  }
  if(vis[xx][yy] == false) 
    cout << "NO" << '\n';
  else {
    string ans = "";
    while(make_pair(xx, yy) != make_pair(-1, -1)) {
      tie(x, y) = par[xx][yy];
      if(y == yy and x == xx + 1) {
        ans += "U";
      } else if(y == yy and x == xx - 1) {
        ans += "D";
      } else if(y == yy + 1 and x == xx) {
          ans += "L";
      } else {
        ans += "R";
      }
      tie(xx, yy) = par[xx][yy];
    }
    ans.pop_back();
    reverse(ans.begin(), ans.end());
    cout << "YES" << endl;
    cout << ans.length() << endl;
    cout << ans << endl;
  }
  return 0;
}
