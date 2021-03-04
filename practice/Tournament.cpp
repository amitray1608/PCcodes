
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  int a[n][n];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) 
      cin >> a[i][j];
  }
  
  map<pair<int, int>, array<int, 2>> mp;
  int ans, x, y;

  ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) 
      if (a[i][j]) {
        int l(0), u(0);
        if (i > 0 and a[i - 1][j]) 
          u = a[i - 1][j];
        if (j > 0 and a[i][j - 1]) 
          l = a[i][j - 1];
        if (l > u) 
          a[i][j] += l, mp[make_pair(i, j)] = {0, 1};
        else 
          a[i][j] += u, mp[make_pair(i, j)] = {1, 0};
        if (a[i][j] > ans) 
          ans = a[i][j], x = i, y = j;
      }
  }

  cout << ans << "\n";
  vector<pair<int, int>> v;
  while (ans--) {
    v.emplace_back(x, y);
    x = x - mp[make_pair(x, y)][0];
    y = y - mp[make_pair(x, y)][1];
  }
  reverse(begin(v), end(v));
  for (auto i: v) 
    cout << i.first << " " << i.second << "\n";
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


