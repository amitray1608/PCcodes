#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;


void solve(){
	int h, w;
  cin >> h >> w;
  vector<string>a(h);
  for(int i = 0; i < h; i++)
    cin >> a[i];
  vector<vector<int>>dp(h, vector<int>(w,0));
  dp[0][0] = 1;
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      if(a[i][j] == '#') continue;
      if(i-1 >= 0)
        dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
      if(j-1 >= 0)
        dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
    }
  }
  cout << dp[h-1][w-1] << endl;
}

int main(){
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1, tt = 0;
//		cin >> t;
		while(t--){
			//tt++;
			//cout << "Case #" << t << ": ";
			solve();
		}
	return 0;
}
