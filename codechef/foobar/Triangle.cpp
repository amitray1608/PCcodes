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
	ll x, y;
	cin >> x >> y;
	ll p = abs(x)+abs(y);
	if(x < 0 and y < 0)
		cout << -p << " " << 0 << " " << 0 << " " << -p << endl;
	else if(x < 0)
		cout << -p << " " << 0 << " " << 0 << " " << p << endl;
	else if(y < 0)
		cout << 0 << " " << -p << " " << p << " " << 0 << endl;
	else
		cout << 0 << " " << p << " " << p << " " << 0 << endl;
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
