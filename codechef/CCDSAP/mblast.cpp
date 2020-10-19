//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

int dp[2004][2004];
string s, t;
int lcs( int n, int m, int k){
	if(n==-1 && m==-1)
		return 0;
	if(n==-1)
		return k*(m+1);
	if(m==-1)
		return k*(n+1); 
	int res = 0;
	if(dp[n][m] != 0)
		res  = dp[n][m];
	else{
		int d = abs(s[n]-t[m]);
		res = min(d+lcs(n-1, m-1, k), k+min(lcs(n-1, m, k), 
				lcs(n, m-1, k)));
	}
	dp[n][m] = res;
		return res;
}

void solve(){
	int k;
	cin >> s >> t;
	cin >> k;
	int n = s.size();
	int m = t.size();
	memset(dp, 0, sizeof dp);
	int ans = lcs(n-1, m-1, k);
	//for(int i = 0; i< n; i++){
		//for(int j = 0; j < m; j++) cout << dp[i][j] << " ";
		//cout << endl;
	//}
	cout << ans;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int tt = 1;
		//cin >> t;
		while(tt--){
			solve();
		}
	return 0;
}
