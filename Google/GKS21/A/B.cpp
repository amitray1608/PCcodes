
#include <bits/stdc++.h>

using namespace std;
#define deb(x) cout << #x << " = " << x << endl;


void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a;
  a.resize(n, vector<int> (m, 0));
  vector<vector<int>> v, h;
  v.resize(n, vector<int>(m, 0));
  h.resize(n, vector<int>(m, 0));
  vector<vector<int>> vr, hr;
  vr.resize(n, vector<int>(m, 0));
  hr.resize(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      v[i][j] = h[i][j] = a[i][j];
      vr[i][j] = hr[i][j] = a[i][j];
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 1; j < n; j++) {
      if (!v[j][i]) continue;
      v[j][i] += v[j - 1][i];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (!h[i][j]) continue;
      h[i][j] += h[i][j - 1];
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = n - 2; j >= 0; j--) {
      if (!vr[j][i]) continue;
      vr[j][i] += vr[j + 1][i];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = m - 2; j >= 0; j--) {
      if (!hr[i][j]) continue;
      hr[i][j] += hr[i][j + 1];
    }
  }

  int res = 0;
  auto count = [&](int i, int j) {
    if(i == 1 or j == 1) return;
    int mini = min(i, j / 2);
    res += max(0, mini - 1);
    mini = min(j, i / 2);
    res += max(0, mini - 1);
  };

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      count(v[i][j], h[i][j]);
      count(v[i][j], hr[i][j]);
      count(vr[i][j], h[i][j]);
      count(vr[i][j], hr[i][j]);
    }
  }
  cout << res << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


