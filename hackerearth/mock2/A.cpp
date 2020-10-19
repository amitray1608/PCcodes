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
		ll a[n];
		for(ll &i : a) cin >> i;
		sort(a, a+n);
		ll mini = a[0], maxi = a[n-1];
		ll ans[n] = {0};
		if(a[0] < 0)
			ans[0] = ((a[0]%MOD)*(a[1]%MOD))%MOD;
		else
			ans[0] = ((a[0]%MOD)*(a[n-1]%MOD))%MOD;
		for(int i = 1; i < n; i++){
			if(a[i] == 0)
				continue;
			else if(a[i] < 0)
				ans[i] = ((a[i]%MOD)*(mini%MOD))%MOD;
			else
				ans[i] = ((a[i]%MOD)*(maxi%MOD))%MOD;
		}
		ll sum = 0;
		for(ll i : ans)
			sum = (sum+i)%MOD;
		
		cout << sum%MOD << endl;
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
