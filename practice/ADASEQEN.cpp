#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;

const int MAXN = 2e3 + 3;
int n, m;
int dp[MAXN][MAXN];
vector<int> val(26);
string s, t;

int recc(int i, int j) {
  if(i < 0 or j < 0) return 0;
  if(dp[i][j] != -1) return dp[i][j];
  int &ans = dp[i][j];
  if(s[i] == t[j]) {
    ans = val[s[i] - 'a'] + recc(i - 1,  j - 1);
  }
  ans = max(ans, recc(i - 1, j));
  ans = max(ans, recc(i, j - 1));
  return ans;
}

void solve(){
  cin >> n >> m;
  for(int &i : val) cin >> i;
  cin >> s >> t;
  memset(dp, -1, sizeof dp);
  recc(n-1, m-1);
  cout << dp[n-1][m-1];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt = 1;
  //cin >> t;
  while(tt--){
  //cout << "Case #" << ++t << ": ";
    solve();
  }
  return 0;
}//Hajimemashite
