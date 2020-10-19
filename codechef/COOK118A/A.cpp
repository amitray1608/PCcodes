#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll power(ll a, ll n) {
	ll p = 1;
	while (n > 0){
		if(n%2) p = p * a;
		
		 n >>= 1, a *= a;
	} 
return p;
}
int main(){
		int t = 1;
		cin >> t;
		while(t--){
			ll n;
			cin >> n;
			ll ans = 0;
			if(__builtin_popcount(n) == 1){
				cout << -1 << endl;
				continue;
			}
			ll x = n-(n/2), half = n/2;
			ll lg = (ll)log2(n);
			ans = (x-1LL)+((half - lg)*2LL) + (power(2LL, lg+1) - 2LL);
			cout <<  ans << endl; 
		}
	return 0;
}	
