
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  if (m < n or n == 2) {
    cout << -1 << '\n';
    return;
  }
  sort(a.begin(), a.end());
  int ans = 0;
  vector<pair<int, int>> res;
  for (int i = 1; i < n; i++) {
    res.push_back(make_pair(a[i - 1].second, a[i].second));
    ans += a[i].first + a[i - 1].first;
  }
  res.push_back({a[n - 1].second, a[0].second});
  ans += a[n - 1].first + a[0].first;
  cout << ans << '\n';
  for (auto i : res) {
    cout << i.first + 1 << ' ' << i.second + 1<< '\n';
  }

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


