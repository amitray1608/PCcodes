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
	int n, m;
	cin >> n >> m;
	ll x = 0, y = 0;
	
	x = (pow(n, 2)+n) / 2;
	y = x;
	ll ii = n;
	for(int i = 2; i <= m; i++){
		y += ii;
		ii++;
	}
	cout << y << endl;
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
//https://foobar.withgoogle.com/?eid=gLBNn
