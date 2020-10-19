#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

const int inf = 1e9;
vector<ll>h, dp;

ll recc(int n, int k) {
  if(n < 0)
    return inf;
  if(dp[n] != -1)
    return dp[n];
  dp[n] = inf;
  int j = 1;
  for(int i = k; i > 0 and n-j >= 0; i--, j++) {
    dp[n] = min(dp[n], recc(n-j, k) + abs(h[n] - h[n-j]));
  }
  return dp[n];
}

void solve(){
  int n, k;
  cin >> n >> k;
  dp.resize(n, -1);
  h.resize(n);
  dp[0] = 0;
  for(ll &i : h) cin >> i;
  ll ans = recc(n-1, k);
 /*
  for(ll &i : dp)
    cout << i << ' ' ;
  cout << endl;
  */
  cout << ans << endl;
}

int main(){
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1, tt = 0;
	//	cin >> t;
		while(t--){
			//tt++;
			//cout << "Case #" << t << ": ";
			solve();
		}
	return 0;
}
