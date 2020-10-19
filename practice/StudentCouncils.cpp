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
  int k, n;
  cin >> k >> n;
  vector<ll> a(n);
  for(ll &i : a) cin >> i;
  sort(a.begin(), a.end());
  auto check = [&](ll x) {
    vector<int> b (a.begin(), a.end());
    ll count = 0;
    for(int i = 0; i+k-1 < n; i++) {
      count += b[i];
      ll x = b[i];
      for(int j = 0; j < k; j++) {
        b[i+j] -= x;
      }
    }
      deb(count);
      deb(x);
    return ((count >= x) ? true : false);
  };
  ll l = 0, h = 1e18;
  while(l <= h) {
    ll mid = l+(h-l)/2;
    if(check(mid))
      l = mid+1;
    else
      h = mid-1;
  }
  cout << h << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  //cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}
  