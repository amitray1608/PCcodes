//Ryuzaki
#include<bits/stdc++.h>
using namespace std;

int dx[]={1, 0, -1, 0};int dy[]={0, 1, 0, -1};

vector<vector<int>> vis;

bool dfs(int i, int j, vector<string> &b) {
  vis[i][j] = true;
  for(int ii = 0; ii < 4; ii++) {
    int x = i + dx[ii], y = j + dy[ii];
    if(x < n and x > 0 and y > 0 and y < n and !vis[x][y] and b[i][j] == b[x][y] ) or b[x]) {
      dfs(x, y, b);
    }
  }
}

void sine() {
  int n;
  cin >> n;
  vis.assign(n, vector<int>(n, 0));
  vector<string> a(n), b;
  for(auto &i : a) cin >> i;
  b = a;
  vector<pair<int, int>> v[11];
  v[0].push_back({0, 1});
  v[1].push_back({1, 0});
  v[2].push_back({n - 2, n - 1});
  v[3].push_back({n - 1, n - 2});
  v[4].push_back({0, 1}, {1, 0});
  v[5].push_back({0, 1}, {n - 1, n - 2});
  v[6].push_back({0, 1}, {n - 2, n - 1});
  v[7].push_back({1, 0}, {n - 2, n - 1});
  v[8].push_back({1, 0}, {n - 1, n - 2});
  v[9].push_back({n - 1, n - 2}, {n - 2, n - 1});
  for(auto i : v) {
    b = a;
    vis.assign(n, vector<int>(n, 0);
    if(i.size() == 1) {
      int x = i[0].first, y = i[0].second;
      b[x][y] = (b[x][y] == '0' ? '1' : '0');
      dfs(0, 0, b);
      if(vis[n - 1][n - 1];
    } else {

    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while(t--) sine();
  return 0;
}
