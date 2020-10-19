//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
ll MODinv(ll x) {
	ll m = MOD, u = 1, v = 0;
	while (m) {
		ll t = x / m;
		x -= t * m; swap(x, m);
		u -= t * v; swap(u, v);
	}
	u %= MOD;
	if (u < 0) u += MOD;
	return u;
}
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int count = 0, o = 0, cl = 0;
	char open = '(', close = ')';
	for(int i = 0; i < n; i++){
		for(int j = 1; j <= n-i ; j++){
			o = 0, cl = 0;
			string ss = s.substr(i, j);
			for(char &c : ss){
				if(c == open)
					o++;
				else if(c == close)
					cl++;
				
				if(cl > o){
					cl--;
					o++;
					count++;
				}
				
			}
		}
	}
	cout << count << endl;
	ll total = (n * (n+1)) / 2;
    ll q = MODinv(total);
    ll change = ((count % MOD) * (q % MOD)) % MOD;
	cout << change << endl;
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

/*
1
5
((())
* */
