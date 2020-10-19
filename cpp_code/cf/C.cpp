//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
ll gcd(ll a, ll b){ 
    if (a == 0) 
        return b;  
    return gcd(b % a, a);  
} 
ll lcm(ll a, ll b){  
    return (a /gcd(a, b) ) * b;  
}
 
void solve(){
	ll a, b ,q;
	cin >> a >> b >> q;
	ll L = lcm(a, b);
	while(q--){
		ll  l, r;
		cin >> l >> r;
		ll count  = 0;
		ll ans = 0;
		ll rem = (r - l + 1) % L;
		ll beg = l % L;
		for(int i = 0; i < L; i++){
			if((i % a) %b != (i % b) % a){
				count++;
				if(i >= beg && i < beg + rem)
					ans++;
			}
		}
		ans += ((r - l + 1) / L) * count;
		cout << ans << " ";
	}
	cout << endl;
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
