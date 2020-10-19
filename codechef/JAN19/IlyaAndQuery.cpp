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
	string s;
	cin >> s;
	int len = s.length();
	int dp[len];
	memset(dp, 0, sizeof dp);
	for(int i = 0; i < len-1; i++){
		if(s[i] == s[i+1]) dp[i+1] = dp[i] + 1;
		else dp[i+1] = dp[i]; 	
	}
	int m;
	cin >> m;
	while(m--){
			int l, r;
			cin >> l >> r;
			l--, r--;
			cout << dp[r] - dp[l] << endl;
	}
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
