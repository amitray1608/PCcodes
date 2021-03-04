
#include <bits/stdc++.h>

using namespace std;

int dx[] = {1, 0, -1, 0}; int dy[] = {0, 1, 0, -1}; //4 Direction
int n;
vector<string> s;
const int maxn = 1e2 + 1;
int dp[maxn][maxn][2];
int res = 0;

int count(int i, int j) {
  int ans = 0;
  for (int k = 0; k < 4; k++) {
    int x = i + dx[k], y = j + dy[k];
    if (x >= 0 and x < n and y >= 0 and y < n) {
      if (s[x][y] == 'W') ans++;
    }
  } 
  return ans;
}

void solve() {
  cin >> n;
  s.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dp[i][j][1] = dp[i][j][0] = 0;
    }
  }
  for (int i = 1; i < n; i++) {
    if (s[i][0] == 'B') {
      dp[i][0][0] = count(i, 0);
      dp[0][i][1] = count(i, 0);
    }
    if (s[0][i] == 'B') {
      dp[0][i][1] = count(0, i);
      dp[0][i][0] = count(0, i);
    }
    if (s[0][i] == '?') {
      
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      if (s[i][j] == '?') {
        
      }
    }
  }
  cout << res << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  //cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite



