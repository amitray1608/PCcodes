#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve(){
  ll n;
  cin >> n;
  vector<ll>a(n), fre;
  fre.resize(32, 1LL);
  for(ll &i : a) cin >> i;
  ll ans = 0;
  for(ll i = 0; i < n; i++) {
    for(int j = 0; j < 32; j++) {
      if(~a[i]&1)
        fre[j]++;
      else {
        ans += fre[j] * (1 << j) * (n - i);
        fre[j] = 1LL;
      }
      a[i] >>= 1LL;
    }
  }
  cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;//, tt = 0;
    //cin >> t;
    while(t--){
        //tt++;
        //cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}

