
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  int n, k;
  cin >> n >> k;
  ld per = k / 100.0, tmp;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  ll acc = accumulate(a.begin(), a.end(), 0LL);
  ll res = 0;
  for (int i = n - 1; i > 0; --i) {
    acc -= a[i];
    ld X = (float)acc;
    tmp = a[i] / X;
    if (tmp > per) {
      ll x = (a[i] * 100 - k * acc);
      ll xx = x / k + (x % k != 0);
      res = max(res, xx);
    }
  }
  cout << res << '\n';
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


