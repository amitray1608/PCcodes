//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

vector<vector<int>> mat;
vector<vector<bool>> vis;
int dx[] = {1 ,0, -1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;

bool isSafe(int x, int y) {
  return (x >= 0 and x < n and y >= 0 and y < n and !vis[x][y]);
}

void solve() {
  cin >> n >> m;
  mat.resize(n, vector<int> (m));
  vis.resize(n, vector<bool> (m, false));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++)
      cin >> mat[i][j];
  }
  queue<pair<int, int>> q;
  q.push({0, 0});
  vis[0][0] = true;
  pair<int, int>ans({INT_MAX, 0});
  while(!q.empty()) {
    auto xx : q.front();
    q.pop();
    int count = 0;
    int x = xx.first, y = xx.second;
    for(int i = 0; i < 4; i++) {
      int nextX = x + dx[i];
      int nextY = y + dy[i];
      if(isSafe(nextX, nextY) and mat[u][v] != mat[nextX][nextY]) {
        vis[nextX][nextY] = true;
        q.push({nextX, nextY});
      } else {
        count++;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  