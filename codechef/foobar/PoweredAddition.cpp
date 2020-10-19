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
	ll maxi = -1e18, diff = 0;
	for(int i = 0; i < n; i++){
		ll x;
		cin >> x;
		maxi = max(maxi, x);
		diff = max(diff, (maxi-x));
	}
	ll count = 0;
	while((1LL << count) - 1 < diff)
		count++;
	cout << count << endl;
	//cout << (ll)log2(diff)-1 << endl;
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
