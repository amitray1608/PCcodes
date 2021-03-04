#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }

  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  
  if (n & 1) {
    cout << 1 << '\n';
  } else {
    ll ans = abs(x[n / 2] - x[n / 2 - 1] + 1LL) * abs(y[n / 2] - y[n / 2 - 1] + 1LL);
    cout << ans << '\n';
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


