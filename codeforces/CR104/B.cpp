#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  ll n, k;
  cin >> n >> k;
  if (n & 1) {
    ll div = (k - 1LL) / ((n - 1LL) / 2LL);
    ll res = k  + div;
    cout << (res % n == 0 ?  n : res % n) << '\n';
  } else {
    cout << (k % n == 0 ? n : k % n) << '\n';
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


