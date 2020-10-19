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
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  ll h = 0;
  for(ll &i : a) cin >> i, h += i;
  auto check = [&] (ll x) {
    ll count = 0, sum = 0;
    for(ll i = 0; i < n; i++) {
      if(a[i] > x) return false;
      sum += a[i];
      if(sum > x)
        sum = a[i], count++;
    }
    return (count+1) <= k;
  };

  ll l = 1, sol = 0;
  while(l <= h) {
    ll mid = l+(h-l)/2;
    // deb(mid);
    if(check(mid))
      sol = mid, h = mid-1;
    else 
      l = mid+1;
  }
  cout << sol << endl;
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


