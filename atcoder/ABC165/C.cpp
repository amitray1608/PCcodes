//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve(){
	ll a, b, n;
	cin >> a >> b >> n;
	ll mini = min(a, min(b, n));
	ll x = ((a*1LL)/(b));
	x -= a*(1LL/(b));
	ll maxi = x;
	for(ll i = 2; i <= mini; i++){
		x = ((a*i)/(b));
		x -= a*(i/(b));
		//cout << x << " ";
		if(x > maxi)
			maxi = x;
	}
	cout << maxi;
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
