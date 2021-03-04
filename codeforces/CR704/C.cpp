
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  vector<vector<int>> f(26);
  for (int i = 0; i < n; i++) {
    f[s[i] - 'a'].push_back(i);
  }

  int maxi = 0, mini = 0, j = m;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == t[--j]) {
      maxi = i;
      break;
    }
  }
  j = 0;
  for (int i = 0; i < n; i++) {
    if (t[j++] == s[i]) {
      mini = i;
    }
    if (j == m - 1) break;
  }
  int ind = t[0] - 'a';
  vector<int> res(m, 0), ans;
  res[0] = f[ind][0];
  f[ind].erase(f[ind].begin(), f[ind].begin() + 1);
  for (int i = 1; i < m; i++) {
    ind = t[i] - 'a';
    int tmp = f[ind].size();
    int x = f[ind][tmp - 1];
    ans.push_back(x - res[i - 1]);
    res[i] = f[ind][0];
    f[ind].erase(f[ind].begin(), f[ind].begin() + 1);
  }
  sort(ans.begin(), ans.end());
  n = ans.size();
  cout << ans[n - 1] << '\n';
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


