//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

ll fact1(ll n){
	ll count = 0;
	for(ll i = 2; i*i <= n; i++){
		if(n%i == 0){
			ll x = n;
			while(x%i == 0) x/=i;
			if(x%i == 1) count++;
			x = n;
			if(i != n/i){
				ll ii = n/i;
				while(x%ii == 0) x/=ii;
				if(x%ii == 1) count++;
			}
		}
	}
return count;
}
ll fact2(ll n){
	ll count = 0;
	for(ll i = 2; i*i <= n; i++){
		if(n%i == 0){
			count++;
			if(n	/i != i) count++;
		}
	}
	return count;
}


void solve(){
	ll n;
	cin >> n;
	if(n == 2)
		cout << 1 << endl;
	else
		cout << fact1(n)+fact2(n-1)+2 << endl;
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
	
