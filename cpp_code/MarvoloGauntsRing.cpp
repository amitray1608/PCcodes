//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
void solve(){
	ll n, p, q, r;
	cin >> n >> p >> q >> r;
	vector<ll>v(n);
	
	for(ll &i : v)
		cin >> i;
		
	ll dp[n][3];
	dp[0][0] = 1ll*p*v[0];
	for(ll i = 1; i<n; i++){
		dp[i][0] = max(dp[i-1][0], 1ll*v[i]*p);
	}
		dp[0][1] = dp[0][0] + 1ll*q*v[0];
	for(ll i = 1; i<n; i++){
		dp[i][1] = max(dp[i-1][1], dp[i][0] + (1ll*v[i]*q));
	}	
	dp[0][2] = dp[0][1] + 1ll*r*v[0];
	for(ll i = 1; i<n; i++){
		dp[i][2] = max(dp[i-1][2], dp[i][1] +(1ll*v[i]*r));
	}
	cout << dp[n-1][2] << endl;
}

int main(){
	#ifndef RAY
	//		freopen("input.txt", "r", stdin);
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
