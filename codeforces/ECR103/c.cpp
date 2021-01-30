#include <bits/stdc++.h>

using namespace std;
#define int int64_t

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n), acc(n);
  for (int &i : a) cin >> i, i--;
  acc[0] = a[0];
  for (int &i : b) cin >> i;
  for (int &i : c) cin >> i;
  
  auto calc = [&]() {
    int maxi = a[0];
    for (int i = 1; i < n; ++i) {
      acc[i] = a[i];
      if (c[i] == b[i]) {
        acc[i] += 2;
      } else {
        acc[i] += 2 + a[i - 1];
        acc[i] -= abs(c[i - 1] - b[i - 1]);
      }
      maxi = max(acc[i], maxi);
    }
    return maxi;
  };

  cout << calc() << '\n';
}

signed main() {
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


