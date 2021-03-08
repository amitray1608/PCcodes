
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  string s[n];
  for (string &i : s) 
    cin >> i;

  vector<vector<int>> ver(n, vector<int> (m, 0));
  vector<vector<int>> hor(n, vector<int> (m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      hor[i][j] = ver[i][j] = 0;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (s[i][j] == '#' or s[i][j - 1] == '#')
        hor[i][j] = hor[i][j - 1];
      else
        hor[i][j] = hor[i][j - 1] + 1;
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 1; j < n; j++) {
      if (s[j][i] == '#' or s[j - 1][i] == '#')
        ver[j][i] = ver[j - 1][i];
      else
        ver[j][i] = ver[j - 1][i] + 1;
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int x, y, X, Y;
    cin >> x >> y >> X >> Y;
    x--, y--, X--, Y--;
    int res = 0;
    for (int i = x; i <= X; i++) {
      res += hor[i][Y] - hor[i][y];
    }
    for (int i = y; i <= Y; i++) {
      res += ver[X][i] - ver[x][i];
    }
    cout << res << '\n';
  }
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


