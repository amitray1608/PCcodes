#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;

const int MAXN = 101;
int dp[MAXN][MAXN];
vector<int> a;
int n;

void solve(){
  cin >> n;
  if(n == 0) exit(0);
  a.assign(n, 0);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  memset(dp, 0, sizeof dp);
  for(int i = 1; i < n; i++)
    dp[i][i] = 0;
  for(int l = 2; l < n; l++) {
    for(int i = 1; i < n - l + 1; i++) {
      int j = i + l - 1;
      dp[i][j] = INT_MAX;
      for(int k = i; k <= j - 1; k++) {
        int cost = dp[i][k] + dp[k + 1][j] + a[k] * a[i - 1];
        if(dp[i][j] > cost)
          dp[i][j] = cost;
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) cout << dp[i][j] << ' ';
    cout << endl;
  }
  cout << dp[1][n - 1] << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  //int t = 1, tt = 0;
  //cin >> t;
  while(1){
  //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
}//Hajimemashite
