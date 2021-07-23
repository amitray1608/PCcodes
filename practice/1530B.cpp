
#include<bits/stdc++.h>

using namespace std;
#define int int64_t
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}; int dy[] = {0, 1, 1, 1, 0, -1, -1, -1}; //8 direction


int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> res;
    for (int k = 0; k < m; k++) {
      res.assign(n, vector<int>(m, 0));
      int i = k;
      for (; i < m; i += 2) {
        res[0][i] = 1;
      }
      if (res[0][m - 1]) {
        i = 2;
      } else {
        i = 1;
      }
      for (; i < n; i += 2) {
        res[i][m - 1] = 1;
      }
      if (res[n - 1][m - 1]) {
        i = m - 3;
      } else {
        i = m - 2; 
      }
      for (; i >= 0; i -= 2) {
        res[n - 1][i] = 1;
      }
      if (res[n - 1][0]) {
        i = n - 3;
      } else {
        i = n - 2;
      }
      for (; i > 0; i -= 2) {
        if (!res[i + 1][0]) res[i][0] = 1;
      }
      bool ok = true;
      for(int ii = 0; ii < n; ii++) {
        for (int j = 0; j < m; j++) {
          for (int l = 0; l < 8; l++) {
            int new_i = ii + dx[l];
            int new_j = j + dy[l];
            if (new_i >= 0 and new_i < n and new_j >= 0 and new_j < m) {
              if (res[new_i][new_j]) { ok = false; break; }
            }
          }
        }
      }
      if (ok) break;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) cout << res[i][j] << ' ';
      cout << '\n';
    }
    cout << '\n';
  }	
  return 0;
} //Hajimemashite

