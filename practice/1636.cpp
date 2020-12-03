#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const ll MOD = 1e9 + 7;
const ll MAXN = 1e6 + 1;
 
ll dp[MAXN], n, s;
vector<ll> coins;
 
ll MODadd(ll &x, ll &y){return (x + y) % MOD;}
 
ll recc(ll i, ll j) {
  if(j == n or i < 0LL) return 0;
  ll &ans = dp[i];
  if(ans != -1) return ans;
  for(ll ii = 1; ii <= s; ii++) {
    if(ii >= coins[j])
    ans = MODadd(ans, dp[i - coins[j]])
  }
  return ans;
}

void solve(){
  cin >> n >> s;
  coins.resize(n);
  for(ll &i : coins) cin >> i;
  memset(dp, -1, sizeof dp);
  dp[0] = 1;
//  for(ll j : coins) {
//    for(ll i = 1; i <= s; i++) {
//      if(j > i) continue;
//      dp[i] = MODadd(dp[i], dp[i-j]);
//    }
//  }
  ll ans = recc(s, 0);
  cout << ans << endl;
}
 
signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ll t = 1, tt = 0;
  //cin >> t;
  while(t--){
  //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
}//Hajimemashite
