//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
const int inf = 1e9 + 5;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
void solve(){
	int n, sum;
	cin >> n >> sum;
	int v[n];
	for(int &i : v) cin >> i;
	int dp[sum+1];
	//memset(dp, inf, sizeof dp);
	for(int i : dp) cout << i << " ";
	dp[0] = 0;
	for(int i = 1; i <= sum; i++){
		for(int j = 0; j < n; j++){
			if(v[j] < i && dp[i - v[j]]+1 < dp[i])
				dp[i] = dp[i- v[j]]+1;
		}
	}
	cout << dp[sum] << endl;
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
