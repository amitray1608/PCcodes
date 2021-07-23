

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  ll n, m;
  cin >> n >> m;
  ll mid = n / 2;

  auto check = [&](ll x, ll y) {
    ll res = (x * y) / __gcd(x, y);
    return res;
  };
  if (m <= 3) {
    for (ll i = mid; i >= 0; i--) {
      ll mul = n - 2 * i;
      if (mul) {
        if (check(i, mul) <= mid) {
          cout << mul << ' ' << i << ' ' << i << '\n';
          return;
        }
      }
    }
  } else {
    if (n & 1) {
      cout << 1 <<  
    } else if (
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


