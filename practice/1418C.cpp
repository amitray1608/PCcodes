#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef double dd;
const int MOD = 1e9 + 7;
const int inf = 1e9;

void solve(){
  int n;
  cin >> n;
  vector<int>a(n);
  vector<int>dp[2];
  dp[0].resize(n+1, inf);
  dp[1].resize(n+1, inf);
  dp[0][0] = 0;
  for(int &i : a) cin >> i;
  for(int i = 1; i <= n; i++) {
    dp[0][i] = min(dp[0][i], dp[1][i-1]);
    dp[1][i] = min(dp[1][i], dp[0][i-1] + a[i-1]);
    if(i > 1) {
      dp[0][i] = min(dp[0][i], dp[1][i-2]);
      dp[1][i] = min(dp[1][i], dp[0][i-2] + a[i-1] + a[i-2]);
    }
  }
  int ans = min(dp[0][n], dp[1][n]);
  cout << ans << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
