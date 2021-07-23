
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll res = 0;
  for (ll i = 1; i < n; i++) {
    while (a[i] <= a[i - 1]) {
      a[i] *= 10;
      res++;
      if (a[i] > a[i - 1]) {
        break;
      }
      if (a[i] + 9 > a[i - 1]) {
        a[i] += a[i - 1] % 10 + 1;
        break;
      }
    }
  }
  cout << res << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  ll t = 1;
  cin >> t;
  for (ll tt = 1; tt <= t; ++tt) {
    cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


