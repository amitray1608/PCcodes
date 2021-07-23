
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  ll n, k, p;
  cin >> n >> k >> p;
  vector<ll> men(n);
  for (ll &i : men) cin >> i;
  vector<ll> key(k);
  for (ll &j : key) cin >> j;
  ll maxi = LONG_MAX;
  sort(men.begin(), men.end());
  sort(key.begin(), key.end());
  for (ll i = 0; i <= k - n; i++) {
    ll dist = 0;
    for (int j = 0; j < n; j++) {
      ll curr = abs(men[j] - key[i + j]) + abs(key[i + j] - p); 
    dist = max(dist, curr);
  }
    maxi = min(maxi, dist);
  }

  cout << maxi << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  ll t = 1;
  //cin >> t;
  for (ll tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


