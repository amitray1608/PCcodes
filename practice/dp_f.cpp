#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

string s, t, ans = "";
vector<vector<int>>dp;

int recc(int n, int m) {
  if(m < 0 or n < 0)
    return 0;
  if(dp[n][m] != -1) {
    return dp[n][m];
  }
  if(s[n] == t[m]) {
    ans.push_back(t[m]);
    return dp[n][m] = 1 + recc(n-1, m-1);
  } else 
    return dp[n][m] = max(recc(n-1, m), recc(n, m-1));
}
void solve(){
  cin >> s >> t;
  int n = (int) s.length(), m = (int)t.length();
  dp.resize(n, vector<int>(m-1));
  int x = recc(n-1, m-1); 
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
}

int main(){
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1, tt = 0;
		//cin >> t;
		while(t--){
			//tt++;
			//cout << "Case #" << t << ": ";
			solve();
		}
	return 0;
}
