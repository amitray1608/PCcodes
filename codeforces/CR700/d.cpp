#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> x, y;
  x.push_back(a[0]);
  int k = 0, prev = -1;
  for (int i = 1; i < n; i++) {
    if (a[i] != a[x.back()]) {
      x.push_back(i);
    } else {
      y.push_back(i);
    }
  }
  int f = x.size(), count = 1;
  for (int i = 1; i < y.size(); i++) {
    if (a[y[i]] != a[y[i - 1]]) count++;
  }
  int ans = (int)x.size() + (int)count;
  cout << ans << '\n';
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


