//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 998244353;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

ll power(ll v, ll p) {
  ll ans = 1;
  while(p > 0) {
    if(p&1)
      ans = (ans*v)%MOD;
    v = (v*v)%MOD;
    p >>= 1;
  }
  return ans;
}


void solve(){
  int n, x;
  cin >> n >> x;
  int a[n];
  ll ans = 1;
  for(int &i : a) cin >> i;
  for(int i = 0; i < n; i++) {
    for(int j = i; j < n; j++) {
      ll sum = 0;
      for(int k = i; k <= j; k++){
        // deb(k-i);
        ll s = power(x, k-i); 
        // deb(s);
        ll c = (s*a[k])%MOD;
        sum = (sum+c)%MOD ;
      }
      deb(sum);
      deb(sum*sum);
      // cout << sum << endl;
      ans = ((ans*((sum*sum)%MOD)))%MOD;
    }
  }
  // cout << "dfgd" << endl;
  // ans = (ans*ans)%MOD;
  cout << ans << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  
/*
1
5 2
5 5 5 5 5

1
5 998244351
5 5 5 5 5
*/