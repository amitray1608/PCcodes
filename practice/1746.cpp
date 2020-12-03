#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;

ll mul(ll x, ll y) {
  return (x % MOD * y % MOD) % MOD;
}

void solve(){
  ll n, m;
  cin >> n >> m;
  vector<int> a(n);
  for(int &i : a) cin >> i;
  vector<ll> dp(n, 0);
  if(n == 1) {
    if(a[0] == 0)
      cout << m;
    else
      cout << 1;
    return 0;
  }

  if(a[1] == 0 and a[0] == 0)
    dp[0] = m;
  else
    dp[0] = 3;

  for(int i = 1; i < n; i++) {
    if(i == n - 1) {
      if(a[i] != 0)
        dp[i] = dp[i - 1];
      else if(a[i] == 0 and a[i - 1] == 0)
        dp[i] = mul(dp[i-1], m);
      else
        dp[i] = mul(dp[i - 1], 3);
    } else if(a[i] != 0) 
      dp[i] = dp[i - 1];
    else {
      if(abs(a[i - 1] - a[i + 1]) == 1)
        dp[i] = mul(dp[i-1], 2LL);
      else if(abs(a[i - 1] - a[i + 1]) == 0)
        dp[i] = mul(dp[i - 1], 3LL);
      else
        dp[i] = dp[i - 1];
    }
  }
  cout << dp[n - 1];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
    //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite
