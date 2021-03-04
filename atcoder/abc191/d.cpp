
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ld x, y, r;
  cin >> x >> y >> r;
  ll lx = (ll)ceil(x - r), md = (ll)(floor)(x + r);
  ll ans = 0LL;
  for(ll i = lx; i <= md; i++) {
    ld p = (ld)(i - x);
    ld diff = (ld)(r * r) - (ld)(p * p);
    ld ly = y - (sqrtl((diff)));
    ld ry = y + (sqrtl((diff)));
    ans += (ll)floor(ry) - (ll)ceil(ly) + 1LL;
  }
  cout << ans;
  return 0;
} //Hajimemashite
