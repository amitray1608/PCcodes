#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;

const int MAXN = 1e3 + 2;
int k, n, m;
string s, ss;
int dp[MAXN][MAXN];

int recc(int i, int j, int kk) {
  if(i >= n or j >= m) return 0;
  int &ans = dp[i][j];
  if(ans != -1) return ans;
  ans = 0;
  if(s[i] == ss[j]) {
    if(kk+1 >= k) {
      ans = recc(i + 1, j + 1, kk + 1) + kk+1;
    } else
      recc(i + 1, j + 1, kk + 1);
  } else
    ans = max({ans, recc(i + 1, j, 0), recc(i, j + 1, 0)}); 
  return ans;
}

void solve(){
  cin >> k;
  if(!k) {
    exit(0);
  }
  cin >> s >> ss;
  memset(dp, -1, sizeof dp);
  n = (int)s.length();
  m = (int)ss.length();
  int ans =  recc(0, 0, 0);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) cout << dp[i][j] << ' ';
    cout << endl;
  }
  cout << ans << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(1){
  //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
}//Hajimemashite
