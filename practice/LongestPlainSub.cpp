#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;

const int MAXN = 6e3 + 101, inf = 1e9;
int dp[MAXN][MAXN];
string s;
int n;

int recc(int i, int j) {
  if(i > j) return 0;
  if(i == j) return 0;
  int &ans = dp[i][j];
  if(dp[i][j] != -1) return ans;
  if(s[i] == s[j]) {
    ans =  recc(i + 1, j - 1);
  } else {
    ans = min(recc(i, j - 1), recc(i + 1, j)) + 1;
  }
  return ans;
}

void solve(){
  cin >> s;
  n = (int)s.size();
  memset(dp, -1, sizeof dp);
  int ans = recc(0, n - 1);
  cout << ans << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
  //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
}//Hajimemashite
