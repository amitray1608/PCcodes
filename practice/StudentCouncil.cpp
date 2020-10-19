#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef double dd;
const ll MOD = 1e9 + 7;

void solve(){
  ll k, n;
  cin >> k >> n;
  vector<ll>a(n);
  for(ll &i : a) cin >> i;
  auto check = [&](ll x) {
    ll total = x*k;
    for(ll i : a) 
      total -= min((ll)i, x);
    return (total <= 0);
  };
  ll l = 0, h = 1e12;
  while(l <= h) {
    ll mid = l + (h - l) / 2;
    if(check(mid)) {
      l = mid + 1;
    } else 
      h = mid - 1;
  }
  cout << h << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t = 1, tt = 0;
  //cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
