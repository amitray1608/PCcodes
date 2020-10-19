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
	map<ll, ll> ls;
	ll sm = 0, mx = 0, z = 0;
	cin >> n;
	ls[0] = 1;
	for(int i=1; i <= n; i++){
		ll k;
		cin >> k;
		sm += k;
		mx = max(mx, ls[sm]);
		z += i-mx;
		ls[sm] = i+1;
	}
	cout << z << endl;
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
	
