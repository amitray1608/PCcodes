//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
void solve(){
	int n, k;
	cin >> n >> k;
	string a;
	cin >> a;
	int dp[n];
	fill(dp, dp+n, 10000);
	dp[0] = 0;
	int i;
	for( i = 0; i<n; i++){
		if(a[i] == '1'){
			for(int j = 0; j<=k; j++){
				if(i+j < n && a[i+j] == '1')
					dp[i+j] = min(dp[i+j], dp[i]+1);
			}
		}
	}
	
	if(dp[n-1] == 10000)
		cout << -1 << endl;
	else
		cout << dp[n-1] << endl;
}

int main(){
	#ifndef RAY
	//	freopen("input.txt", "r", stdin);
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
