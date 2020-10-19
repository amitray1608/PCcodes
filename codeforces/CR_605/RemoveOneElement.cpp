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
	ll n;
	cin >> n;
	ll a[n];
	for(ll &i : a) cin >> i;
	vector<ll>lef(n, 1);
	vector<ll>rig(n, 1);
	ll ans = 1;
	for(int i = 1; i < n; i++){
		if(a[i] > a[i-1])
			lef[i] = lef[i-1]+1;
		ans = max(ans, lef[i]);
	}
	
	for(int i = n-2; i >= 0; i--){
		if(a[i] < a[i+1])
			rig[i] = rig[i+1]+1;
		ans =  max(ans, rig[i]);
	}
	
	for(int i = 0; i < n-2; i++){
		if(a[i] < a[i+2]) ans = max(ans, lef[i] + rig[i+2]);
	}
	cout << ans << endl;
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
	
