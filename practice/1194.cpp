
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

int dx[] = {1, 0, -1, 0}; int dy[] = {0, 1, 0, -1}; //4 Direction
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<string> v(n);
  int x, y;
  minpq<array<int, 3>> q;
  vector<vector<bool>> vis(n, vector<bool>(m, false));
  vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
  vector<vector<int>> disa(n, vector<int>(m, INT_MAX));
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    for (int j = 0; j < m; j++)  {
      if (v[i][j] == 'M') {
        q.push({0, i, j});
        vis[i][j] = true;
        dis[i][j] = 0;
        v[i][j] = '.';
      }
      if (v[i][j] == 'A') {
        x = i, y = j;
        v[i][j] = '.';
      }
    }
  }

  auto valid = [&](int i, int j) {
    return (i >= 0 and i < n and j >= 0 and j < m and (v[i][j] == '.'));
  };
  bool ok = false;
  while (!q.empty()) {
    auto [c, i, j] = q.top();
    q.pop();
    if (dis[i][j] < c) continue;
    for (int k = 0; k < 4; k++) {
      int newi = i + dx[k];
      int newj = j + dy[k];
      if (valid(newi, newj) and dis[newi][newj] > dis[i][j] + 1) {
        dis[newi][newj] = dis[i][j] + 1; 
        q.push({dis[newi][newj], newi, newj});
      }
    }
  }
  
  queue<array<int, 3>> pq;
  pq.push({x, y, 0});
  int resx, resy;
  vector<vector<array<int, 2>>> path(n, vector<array<int, 2>>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      path[i][j][0] = i;
      path[i][j][1] = j;
    }
  }
  vis.resize(n, vector<bool>(m, false));
  vis[x][y] = 1;
  disa[x][y] = 0;
  while (!pq.empty()) {
    auto [i, j, c] = pq.front();
    pq.pop();
    if ((i == n - 1 or i == 0 or j == m - 1 or j == 0) and dis[i][j] > c) {
      ok = true;
      resx = i;
      resy = j;
      break;
    }
    for (int k = 0; k < 4; k++) {
      int newi = i + dx[k];
      int newj = j + dy[k];
      if (valid(newi, newj) and !vis[newi][newj]) {
        if (disa[newi][newj] > c + 1)
          pq.push({newi, newj, c + 1});
        vis[newi][newj] = true;
        path[newi][newj] = {i, j};
        disa[newi][newj] = min(disa[newi][newj], c + 1);
      }
    }
  }

  if (!ok) {
    cout << "NO" << '\n';
    return 0;
  } else {
    string res = "";
    path[x][y] = {-1, -1};
    auto [xx, yy] = path[resx][resy];
    while (xx != -1 and  yy != -1) {
      if (xx - resx == 1) res += "U";
      if (resx - xx == 1) res += "D";
      if (resy - yy == 1) res += "R";
      if (yy - resy == 1) res += "L";
      resx = xx; resy = yy;
      xx = path[resx][resy][0];
      yy = path[resx][resy][1];
    }
    reverse(res.begin(), res.end());
    cout << "YES" << '\n';
    cout << res.size() << '\n';
    cout << res << '\n';
  }
  return 0;
} //Hajimemashite

