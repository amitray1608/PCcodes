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
	int n, m;
	cin >> n >> m;
	int a[n+1][m+1];	
	int dp[n+2][m+2];
	memset(a, 0, sizeof a);
	memset(dp, 0, sizeof dp);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
			dp[i][j]=max(max(a[i][j],a[i-1][j]),max(dp[i-1][j-1],dp[i-1][j+1]));
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			//cout << dp[i][j];
			if(a[i][j] == dp[i][j])
			cout << 1;
			else 
				cout << 0;
		}
		cout << endl;
	}
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
