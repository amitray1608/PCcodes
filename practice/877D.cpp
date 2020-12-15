#include<bits/stdc++.h>

using namespace std;

int dx[] = {1, 0, -1, 0}; int dy[] = {0, 1, 0, -1}; //4 Direction

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  string s[n];
  for(string &i : s) cin >> i;
  int x, y, xx, yy;
  cin >> x >> y >> xx >> yy;
  x--, y--, xx--, yy--;
  
  const int inf = 1e9;
  vector<vector<int>> dis(n, vector<int>(m, inf));
  deque<array<int, 4>> q;
  q.push_front({x, y, 0, -1});
  dis[x][y] = 0;
  
  auto valid = [&](int u, int v) {
    return (u >= 0 and v >= 0 and u < n and v < m and s[u][v] == '.');
  };
  
  while(!q.emtpy()) {
    auto [u, v, c, d] = q.front();
    q.pop_front();
    
    for(int i = 0; i < 4; i++) {
      int uu = u + dx[i], vv = v = dy[i];
      if(c == k) {
        if(dis[uu][vv] > dis[u][v] + 1) {
          dis[uu][vv] = dis[u][v] + 1;
          q.push_back({vv, uu, 1, i});
        }
      } else {

      }
    }
  }

  return 0;
}
