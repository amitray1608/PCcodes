
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

int dx[] = {1, 0, -1, 0}; int dy[] = {0, 1, 0, -1}; //4 Direction
const int maxn = 51;
int vis[maxn][maxn];
int a[maxn][maxn];
int n;

bool valid(int x, int y) {
  return (x >= 0 and y >= 0 and x < n and y < n and !vis[x][y] and a[x][y]);
}

void dfs(int x, int y, vector<vector<int>> &d) {
  vis[x][y] = true;
  d[x][y] = true;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (valid(nx, ny) and !d[nx][ny]) dfs(nx, ny, d);
  }
}

int dist(int x, int y, int xx, int yy) {
  return (pow((x - xx), 2) + pow((y - yy), 2));
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  cin >> n;
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  x1--, y1--, x2--, y2--;
  memset(a, 0, sizeof a);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char x; cin >> x;
      a[i][j] = (x == '0');
    }
  }
  memset(vis, 0, sizeof vis);
  vector<vector<int>> d(n, vector<int>(n, 0));
  dfs(x1, y1, d);
  if (vis[x2][y2]) {
    cout << 0 << '\n';
    return 0;
  }
  memset(vis, 0, sizeof vis);
  vector<vector<int>> d1(n, vector<int>(n, 0));
  dfs(x2, y2, d1);
  int mini = 1e10;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!d[i][j]) continue;
      for (int k = 0; k < n; k++) {
        for (int l = 0; l < n; l++) {
          if (!d1[k][l]) continue;
          mini = min(mini, dist(i + 1, j + 1, k + 1, l + 1));
        }
      }
    }
  }
  cout << mini << '\n';
  return 0;
} //Hajimemashite

