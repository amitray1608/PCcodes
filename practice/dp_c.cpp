#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
const int inf = 1e9;
vector<vector<int>>h, dp;

int recc(int n, int x) {
  if(dp[n][x] != -1)
    return dp[n][x];
  dp[n][0] = h[n][0], dp[n][1] = h[n][1], dp[n][2] = h[n][2];
  dp[n][0] += max(recc(n-1, 1), recc(n-1, 2));
  dp[n][1] += max(recc(n-1, 0), recc(n-1, 2));
  dp[n][2] += max(recc(n-1, 0), recc(n-1, 1));
  return dp[n][x];
}

void solve(){
  int n;
  cin >> n;
  h.resize(n, vector<int>(3, 0));
  dp.resize(n, vector<int>(3, -1));
  for(int i = 0; i < n; i++) 
    cin >> h[i][0] >> h[i][1] >> h[i][2];
  dp[0][0] = h[0][0], dp[0][1] = h[0][1], dp[0][2] = h[0][2];
  ll ans = recc(n-1, 0);
  cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
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
