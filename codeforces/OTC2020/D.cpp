//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int inf = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
int dp[2003][2003];
int fun(string s, string t, int n, int m, int k){
	if(n == 0 and m == 0)
		return 0;
	if(dp[n][k])
		return dp[n][k];
	if(if)
		return dp[n][m] = 1+fun(s, t, n-1, m-1);
	else 
		return max(dp[n][m-1] = fun(s, t, n, m-1), dp[n-1][m] = fun(s, t, n-1, m-1, ));
}
void solve(){
	memset(dp, 0, sizeof dp);
	string s, t;
	cin >> s >> t;
	int k;
	cin >> k;
	int n = s.size();
	int m = t.size();
	int ans = fun(s, t, n, m, k);
	cout << ans << endl;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		//cin >> t;
		while(t--){
			solve();
		}
	return 0;
}
