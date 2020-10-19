//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
int siz = 1e6+1;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
bool isPower(ll x, ll y) {  
    ll res1 = log(y) / log(x); 
    long double res2 = log(y) / log(x);
    return (res1 == res2); 
} 
void solve(){
	bool prime[siz];
	memset(prime, true, sizeof prime);
	for(int i = 2; i*i <= siz; i++){
		if(prime[i]){
			for(int j = i*i; j <= siz; j+=i)
				prime[i] = false;
		}	
	}
	ll n;
	cin >> n;
	ll count = 0;
	while(1){
		for()
	}
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
