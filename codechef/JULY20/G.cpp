//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 998244353;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

ll n, x;
vector<ll>a;

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
  cin >> n >> x;
  a.resize(n);
  for(ll &i : a) cin >> i;
  vector<ll> p(n, 0);
  for(int i = 0; i < n; i++) {
    p[i] = power(x, i);
    p[i] = (p[i]*a[i])%MOD;
  }
  for(int i = 1; i < n; i++)
    p[i] = (p[i] + p[i-1])%MOD;
  
  for(int i = 0; i < n; i++) {
    p[i] = (p[i]*p[i])%MOD;
  }
  ll ans = 1;
  reverse(p.begin(), p.end());
  for(int i = 0; i < n; i++){
    ll c = power(p[i], (i+1))%MOD;
    ans = (ans*c)%MOD;
  }
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
5 998244351
5 5 5 5 5

1
5 2
5 5 5 5 5

253808779
*/