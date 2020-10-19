//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e8 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

//ll mpow(ll x, ll n) {
	//ll ans = 1;
	//while (n != 0) {
		//if (n & 1) ans = ans * x % MOD;
		//x = x * x % MOD;
		//n = n >> 1;
	//}
	//return ans;
//}
void solve(){
	ll n, m;
	cin >> n >> m;
	ll count = 0;
	if(n == m){
		cout << count << endl;
		return;
	}
	if(n > m)
		swap(n, m);
	while(m%8 == 0 and m/8 >= n)
		m/=8, count++;
	while(m%4 == 0 and m/4 >= n)
		m/=4, count++;
	while(m%2 == 0 and m/2 >= n)
		m/=2, count++;
	if(n == m)
		cout << count << endl;
	else
		cout << -1 << endl;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1, tt = 0;
		cin >> t;
		while(t--){
			//tt++;
			//cout << "Case " << tt << ": ";
			solve();
		}
	return 0;
}
