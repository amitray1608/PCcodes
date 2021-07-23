
#include<bits/stdc++.h>

using namespace std;

int dx[] = {1, 0, -1, 0}; int dy[] = {0, 1, 0, -1}; //4 Direction
int n, m;
vector<string> a;
int nodeCount = 0;
vector<vector<int>> vis;
int dfsCount = 0;

bool valid(int i, int j) {
  return (i >= 0 and i < n and j >= 0 and j < m and 
      !vis[i][j] and a[i][j] == '#'); 
}

void dfs(int i, int j) {
  vis[i][j] = true;
  dfsCount++;
  for (int k = 0; k < 4; k++) {
    int new_i = i + dx[k];
    int new_j = j = dy[k];
    if (valid(new_i, new_j)) dfs(new_i, new_j);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  cin >> n >> m;
  a.resize(n);
  vector<pair<int, int>> pos;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < m; j++) { 
      if (a[i][j] == '#') {
        nodeCount++;
        pos.push_back({i, j});
     }  
    }
  }
  if (nodeCount <= 2) {
    cout << -1 << '\n';
    return 0;
  }
  int res = 2;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '.') continue;
      a[i][j] = '.';
      vis.assign(n, vector<int>(m, false));
      for (auto k : pos) {
        if (k.first != i and k.second != j) {
          dfsCount = 0;
          dfs(k.first, k.second);
          if (nodeCount - 1 != dfsCount) {
            res = 1;
          }
        }
      }
      a[i][j] = '#';
    }
  }
  cout << res << '\n';
  return 0;
} //Hajimemashite

