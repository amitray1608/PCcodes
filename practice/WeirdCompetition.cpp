#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;
#define ff first
#define ss second
const int MAXN = 251, INF = 1e7;
int n, W;
int strength[MAXN], weight[MAXN];
vector<vector<int>> dp(MAXN, vector<int>(MAXN, -1));
int ans = 0;

int recc(int idx, int val){
  if(idx == n){
    if(val >= W) return 0;
    else return INF;
  }
  if(dp[idx][val] != -1) 
    return dp[idx][val];
  int v1 = recc(idx + 1, val);
  int v2 = recc(idx + 1, val + strength[idx]) + weight[idx];
  dp[idx][val] = min(v2, v1);
  return dp[idx][val];
}
void solve(){
  cin >> n >> W;
  for(int i = 1; i <= n; ++i) cin >> weight[i];
  for(int i = 1; i <= n; ++i) cin >> strength[i];
  int anss = recc(1, 0);
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= W; j++) cout << dp[i][j] << setw(3);
    cout << endl;
  }
  cout << ans << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
  //cout << "Case #" << ++t << ": ";
    solve();
  }
  return 0;
}//Hajimemashite
