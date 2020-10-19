#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;

void solve(){
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for(ll &i : a) cin >> i;
  ll ans = 0;
  auto check = [&](ll x) {
    for(ll i = 0; i < n - k; i++) {
      if(abs(a[i] - a[i + k]) <= x) {
        ans = (a[i] + a[i + k]) / 2;
        return true;
      }
    } 
    return false;
  };
  ll l = 0, h = a[n - 1] - a[0];
  while(l <= h) {
    ll mid = l + (h - l) / 2;
    if(check(mid)) 
      h = mid - 1;
    else
      l = mid + 1;
  }
  cout << ans << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
  //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
}//Hajimemashite
