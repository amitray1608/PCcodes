#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;
#define ff first
#define ss second

const int MAXN = 3010;
string s, t, res;
int dp[MAXN][MAXN];

int rec(int i, int j) {
  if(i < 0 || j < 0) return 0;
  if(dp[i][j] != -1) return dp[i][j];
  int &ans = dp[i][j];
  if(s[i] == t[j]) {
    ans = 1 + rec(i - 1, j - 1);
  }
  ans = max(ans, rec(i - 1, j));
  ans = max(ans, rec(i, j- 1));
  return ans;
}

void trace(int i, int j) {
  if(i < 0 || j < 0) return;
  int ans = rec(i, j);
  if(s[i] == t[j] && ans == 1 + rec(i - 1, j - 1)) {
    res += s[i];
    trace(i - 1, j - 1);
    return;
  }
  if(rec(i - 1, j) == ans) trace(i - 1, j);
  else trace(i, j - 1);
}

void solve(){
  cin >> s >> t;
  int n = (int)s.size(), m = (int)t.size();
  memset(dp, -1, sizeof dp);
  res = "";
  rec(n - 1, m - 1);
  trace(n - 1, m - 1);
  reverse(res.begin(), res.end());
  cout << res << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
  return 0;
}//Hajimemashite


