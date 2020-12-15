#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;

ll add(ll x, ll y) {
  return (x % MOD + y % MOD) % MOD;
}

void solve(){
  ll n, m;
  cin >> n >> m;
  vector<int> a(n);
  for(int &i : a) cin >> i;
  vector<vector<ll>> dp(n+1, vector<ll>(m + 2, 0));
  for(int i = 1; i < m + 1; i++) {
    if(a[0] == 0)
      dp[0][i] = 1;
    else
      dp[0][i] = (a[0] == i ? 1 : 0);
  }
  for(int i = 1; i < n; i++) {
    for(int j = 1; j < m + 1; j++) {
      if(a[i] == 0)
        dp[i][j] = add(add(dp[i - 1][j - 1], dp[i - 1][j]), dp[i - 1][j + 1]);
      else
        dp[i][j] = (a[i] == j ? add(add(dp[i - 1][j - 1], dp[i - 1][j]), dp[i - 1][j + 1]): 0);
    }
  }
  ll ans = 0;
  for(int i = 1; i < m + 1; i++) {
    ans = add(ans, dp[n - 1][i]);
  }
//  for(int i = 0; i < n + 1; i++) {
//    for(int j = 1; j < m + 1; j++) cout << dp[i][j] << ' ';
//    cout << endl;
//  }
  cout << ans;
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
