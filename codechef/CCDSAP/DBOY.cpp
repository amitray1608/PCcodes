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
	int n;
	cin >> n;
	int a[n];
	for(int &i : a) cin >> i;
	int b[n];
	for(int &i : b) cin >> i;
	sort(a, a+n);
	sort(b, b+n);
	int dp[1004];
	int maxi = *max_element(a, a+n);
	for(int i = 0; i < 2*maxi+1; i++) dp[i] = MOD;
	dp[0] = 0;	
	for(int i = 0; i < n; i++){
		for(int j = b[i]; j < 2*maxi+1; j++){
			if(dp[j] > dp[j-b[i]]+1)
				dp[j] = dp[j-b[i]]+1;
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
		ans+=dp[a[i]*2];

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
