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
	ll a, b, n;
	cin >> n >> a >> b;
	if(a == 0)
		cout << 0;
	else{
    	ll ans = a*(n/(a+b));
    	if(n%(a+b) <= a)
    		ans += (n%(a+b));
 
    	else
    		ans += a;
	    cout<< ans;
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
