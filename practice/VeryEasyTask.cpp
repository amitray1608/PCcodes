//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve() {
  ll n, x, y;
  cin >> n >> x >> y;
  auto check = [&](ll xx) {
    ll count = xx/x + xx/y;
    return count >= n-1;
  };
  ll l = 0, r = max(x, y)*n-1;
  while(l <= r) {
    ll mid = l+(r-l)/2;
    if(check(mid)) {
      r = mid-1;
    } else {
      l = mid+1;
    }
  }
  cout << l+min(x, y) << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  // cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  