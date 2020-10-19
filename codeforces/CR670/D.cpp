//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
vector<ll> dp;

ll recc(ll n) {
  if(n == 0)
    return 0;
  if(dp[n] != -1)
    return dp[n];
  dp[n] = (dp[n] + (recc(n-1) + recc(n-1))%MOD)%MOD;
  return dp[n];
}


void solve() {
  ll n;
  cin >> n;
  dp.resize(n+1, -1);
  dp[1] = 2;
  ll ans = recc(n);
  cout << ans;
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