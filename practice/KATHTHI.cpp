#include<bits/stdc++.h>

using namespace std;

int dx[] = {1, 0, -1, 0}; int dy[] = {0, 1, 0, -1}; //4 Direction

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    const int inf = 1e9;
    vector<vector<int>> dis(n, vector<int>(m, inf));
    dis[0][0] = 0;
    deque<pair<int, int>> q;
    q.push_back({0, 0});
    while(!q.empty()) {
      int u = q.front().first, v = q.front().second;
      q.pop_front();
      for(int i = 0; i < 4; i++) {
        int x = u + dx[i], y = v + dy[i];
        if(x >= 0 and x < n and y >= 0 and y < m) {
          int w = !(a[u][v] == a[x][y]);
          if(dis[u][v] + w < dis[x][y]) {
            dis[x][y] = dis[u][v] + w;
            (w ? q.push_back({x, y}) : q.push_front({x, y}));
          }
        }
      }
    }
    cout << dis[n - 1][m - 1] << '\n';
  }
  return 0;
}
