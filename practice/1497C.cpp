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
  ll sum = 0;
  for (ll i = mid; i >= 0; i--) {
    ll mul = n - 2 * i;
    if (mul) {
      if (check(i, mul) <= mid) {
        cout << mul << ' ' << i << ' ' << i << ' ';
        sum += mul + i + i;
        break;
      }
    }
  }
  for (ll i = sum; i < k; i++) 
    cout << 1 << ' ';
  cout << '\n';
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
