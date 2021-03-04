
#include <bits/stdc++.h>

using namespace std;
using ll = long long;


void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n), dp(n, 0);
  ll maxi = 0;
  for (ll &i : a) cin >> i, maxi = max(maxi, i);
  ll sum = accumulate(a.begin(), a.end(), 0LL);
  ll count = 0LL;
  if (sum == n) {
    cout << 0 << '\n';
    return;
  }

  function<bool(ll)> recc = [&](ll x) {
    if (x >= n) return true;
    if (dp[x]) return false;
    ll newx = x + a[x];
    bool ok = recc(newx);
    a[x]--;
    if (a[x] <= 1 or !ok) {
      dp[x] = 1;
      return false;
    }
    return true;
  };

  auto maxpos = [&]() {
    ll x = 0, pos = -1;
    for (ll j = 0; j < n; j++) {
      if (a[j] > x) {
        x = a[j];
        pos = j;
      }
    }
    return pos;
  };

  ll k = maxi;
  while (1 < k) {
    ll x = maxpos();
    ll maxi = *max_element(a.begin(), a.end());
    count += maxi - 1LL;
    ll newi = x, newj = min(k + a[k], n - 1LL);
    while (newj < n) {
      for (ll itr = newj - 1; itr > newi + 1; itr--) {
        a[itr] = 1;
      }
      ll tmp = a[newj];
      a[newi] = a[newj] = 1;
      newi = newj;
      newj = newj + a[newj];
    }
    for (ll i = n - 1; i >= newi + 1; i--) {
      a[i] = 1;
    }
    a[newi] = 1;
    k = *max_element(a.begin(), a.end());  
  }
  cout << count << '\n';
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


