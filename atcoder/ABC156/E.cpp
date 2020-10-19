//“Make it work, make it right, make it fast.” – Kent Beck
//SPOJ DP problem.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
ll C[500007];

void solve(){
	int n;
	cin >> n;
	int a[n][2];
	for(int i = 0; i < n; i++)
		cin >> a[i][0] >> a[i][1];
	int dp[n][2] = {0};
	dp[0][0] = a[0][0]; 
	dp[0][1] = a[0][1];
	for(int i = 1; i < n; i++){
		dp[i][0] = max(dp[i-1][0]+a[i][0] + abs(a[i][1]-a[i-1][1]), dp[i-1][1]+a[i][0] + abs(a[i][1]-a[i-1][0]));
		dp[i][1] = max(dp[i-1][0]+a[i][1] + abs(a[i][0]-a[i-1][1]), dp[i-1][1]+a[i][1] + abs(a[i-1][0]-a[i][0]));
	}
	cout << max(dp[n-1][0], dp[n-1][1]) << endl;
}

int main(){
	#ifndef ONLINE_JUDGE
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
