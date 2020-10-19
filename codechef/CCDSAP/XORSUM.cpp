//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
int dp[1024];

void solve(){
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	memset(dp, 0, sizeof dp);
	dp[0] = 1;	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 1024; j++)
			dp[j^a[i]] |= dp[j];
	}
	int ans = k;
	for(int i = 0; i < 1024; i++)
		if(dp[i])
			ans = max(ans, k^i);
	cout << ans << endl;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		cin >> t;
		while(t--){
			solve();
		}
	return 0;
}
