
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n;
    cin >> n;
    if (n == 2) {
      cout << -1 << '\n';
      continue;
    }
    if (n == 1) {
      cout << 1 << '\n';
      continue;
    }
    int delta = 3, j = 1;
    vector<vector<int>> res(n, vector<int>(n));
    res[0][0] = 1;
    for (int i = 1; i < 2 * n; i++) {
      int row = i;
      int col = 0;
      if (row >= n) {
        row = n - 1;
        col = j++;
        while (col <= n - 1) {
          res[row][col] = delta++;
          row--, col++;
        }
        continue;
      }
      while (row >= 0 and col <= i) {
        res[row][col] = delta++;
        row--; col++;
      }
    }
    res[n - 1][n - 1] = 2;
    for (int i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        cout << res[i][j] << ' ';
      } cout << '\n';
    }
  }	
  return 0;
} //Hajimemashite

