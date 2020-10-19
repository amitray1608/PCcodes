//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
typedef long double dd;
const ll siz = 1e6 + 5;
const ll MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve() {
  ll h, w, n;
  cin >> h >> w >> n;
  auto check = [&](ll x) {
    return (((x/h)*(x/w)) >= n);
  };

  ll l = 1, r = 1;
  while(!checfk(r)) r <<= 1;
  while(l <= r) {
    ll mid = l+(r-l)/2;
    if(check(mid)) {
      r = mid-1;
    } else {
      l = mid+1;
    }
  }
  cout << l << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  ll t = 1;
  // cin >> t;
  for(ll tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  