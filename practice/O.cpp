#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int mod = 1e9 + 7;

const int MAXN = 21;
int dp[MAXN + 1][(1 << MAXN) + 1];
int ar[MAXN + 1][MAXN + 1];
int n;

int rec(int i, int mask) {
  if(i == n) return 1;
  if(dp[i][mask] != -1) return dp[i][mask];
  int res = 0;
  for(int j = 0; j < n; ++j) {
    if(ar[i][j] && !(mask & (1 << j))) {
      int ans = rec(i + 1, mask | (1 << j));
      ans %= mod;
      res = (res + ans) % mod;
    }
  }
  return dp[i][mask] = res;
} 

void solve(){
  cin >> n;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      cin >> ar[i][j];
    }
  }
  memset(dp, -1, sizeof dp);
  cout << rec(0, 0) << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  // cin >> t;
  while(t--){
  //cout << "Case #" << ++t << ": ";
    solve();
  }
  return 0;
}//Hajimemashite
