//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
int dp[n+1], n;

int recc(int x){
	if(x = n)
		return 1;
	if(dp[i] > 0)
		return dp[i];
	for(int i = x+x; i <= n; i+=x)
		return max(dp[i], recc(i));
}

void solve(){
	cin >> n;
	int a[n+1];
	int ans = 0;
	for(int i = 1; i <= n; i++) cin >> a[i], dp[i] = -1;
	//memset(dp, 1, sizeof dp);
	//for(int i = 1; i <= n; i++){
		//for(int j = i+i; j <= n; j+=i){
			//if(a[j] > a[i])
				//dp[j] = max(dp[j], dp[i]+1);
		//}
		//ans = max(ans, dp[i]);
	//}
	recc(1);
	for(int i = 1; i <= n; i++) ans = max(ans, dp[i]);
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
