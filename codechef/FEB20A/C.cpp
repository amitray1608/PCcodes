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
	ll n, p, pp;
	cin >> n >> p;
	pp = p;
	ll a[n], ans[n] = {0};
	for(ll &i : a){ 
		cin >> i;
	}
		for(int i = n-1; i >= 0; i--){
			ll x = (p/a[i]);
			if(a[i] == 1) continue;
			if(p % a[i] != 0){
				ans[i] = x+1;
				break;	
			}else{
				ans[i] = x-1;
				p -= (x-1)*a[i];
			}
		}
	ll c = 0;
	for(int i= 0; i < n; i++){
			c += a[i]*ans[i];
		 
		//cout << ans[i] << " ";
	}
	//cout << endl;
	//deb(c);
	if(c <= pp)
		cout << "NO\n";
	else{
		cout << "YES\n";
		for(ll &i : ans) cout << i << ' ';
		cout << endl;
	}
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
