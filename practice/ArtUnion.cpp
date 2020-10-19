#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef double dd;
const int MOD = 1e9 + 7;

void solve(){
  int m, n;
  cin >> m >> n;
  vector<vector<int>>a(m, vector<int>(n)), dp(m, vector<int>(n, 0));
  for(auto &i : a) 
    for(auto &j : i)
      cin >> j;
  dp[0][0] = a[0][0];
  for(int i = 1; i < n; i++)
    dp[0][i] = dp[0][i-1] + a[0][i];
  for(int i = 1; i < m; i++) {
    for(int j = 0; j < n; j++) {
        if(j == 0)
          dp[i][j] = dp[i-1][j]+a[i][j];
        else
          dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + a[i][j];
    }
  }
  for(int i = 0; i < m; i++)
    cout << dp[i][n-1] << ' ';
  cout << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
