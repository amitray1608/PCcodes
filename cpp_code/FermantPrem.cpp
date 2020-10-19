//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
ll power(ll a, ll n, ll p){

	ll ans = 1;
	a = a%p;
	while(n>0){
		if(n&1){
			ans = (ans*a)%p;
		}
		n = n >> 1;
		a = (a*a)%p;
	}
	return ans;
}
void solve(){
	ll n, k = 3;
	cin >> n;
	bool flag = true;
	if(n == 1 || n == 4) flag = false;
		
		while(k > 0){
			ll a = 2+rand()%(n-4);
		
			if(__gcd(a, n) != 1){
				flag = false; break;
			}
			if(power(a, n-1, n) != 1)
				flag = false;
			
			k--;
		}
		(flag)  ? cout << "Prime\n" : cout << "Composite" << endl;
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
	

