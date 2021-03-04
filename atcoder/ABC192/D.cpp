
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  string s;
  cin >> s;
  ll m;
  cin >> m;
  
  ll maxi = 0LL;
  for (char c : s) {
    maxi = max(maxi, (ll)c - '0');
  }
  maxi += 1;
  if (s.size() == 1) {
    cout << (m >= stoll(s) ? 1 : 0) << '\n';
    return;
  }
  ll n = (int)s.size();
  auto check = [&](ll x) {
    if((n + 1) > m * logl(x)) return false;
    ll cp = 0, res = 1LL;
    for (ll i = n - 1LL; i >= 0LL; i--) {
      cp += (ll)(s[i] - '0') * res;
      if (res > m or cp > m) return false;
      res *= x;
    }
    if (cp <= m) return true;
    return false;
  };

  if(!check(maxi)) return void(cout << 0 << "\n");
  ll l = maxi, r = maxi, ans;
  while(check(r)) r <<= 1;
  while (l <= r) {
    ll mid = l + (r - l) / 2LL;
    if (check(mid)) {
      ans = mid;
      l = mid + 1LL;
    } else {
      r = mid - 1LL;
    }
  }
  cout << max(0LL, ans - maxi + 1) << '\n';
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


