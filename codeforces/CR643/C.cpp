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
	ll a, b, c, d, tri = 0;
	cin >> a >> b >> c >> d;
	for(ll i = c; i <= d; i++){
		ll mini = max(i-a+1, b);
		for(ll j = b; j <= c; j++){
			ll abc = i+j-c;
			ll bcd = d-c+1;
			if(i+j <= d)
				tri += abc;
			if(i+j > d)
				tri += bcd;
		}
	}
	cout << tri << endl;	
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
