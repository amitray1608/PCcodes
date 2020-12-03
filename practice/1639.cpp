#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;
const int MAXN = 5e3 + 1;

int dp[MAXN][MAXN];
string s, ss;
int n, m;

int recc(int i, int j) {
  if(!i) return j;
  if(!j) return i;
  int &ans = dp[i - 1][j - 1];
  if(ans != -1) return ans;
  ans = INT_MAX;
  if(s[i - 1] == ss[j - 1])
    ans = min(ans, recc(i - 1, j - 1));
  else{
    ans = min(ans, recc(i, j - 1) + 1);
    ans = min(ans, recc(i - 1, j) + 1);
    ans = min(ans, recc(i - 1, j - 1) + 1);
  }
  return ans;
}

void solve(){
  cin >> s >> ss;
  n = (int)s.size();
  m = (int)ss.size();
  memset(dp, -1, sizeof dp);
  int ans = recc(n, m);
  cout << ans  << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
    //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite
