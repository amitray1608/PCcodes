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
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	if(a > b) swap(a, b);
	ll dist = abs(a-b);
	
	//~ deb(dist);
	ll xa = c-d, xb = c+d;
	ll distx = abs(xb - xa);
	if(xa >= a && xb <= b)
		cout << dist - distx << endl;
	else if(xa <= a && xb >= b)
		cout << 0 << endl;
	else if((xb <= a)|| xa >= b)
		cout << dist << endl;
	else if(xa <= a && xb <= b)
		cout << dist - abs(xb-a) << endl;
	else if(xa >= a && b <= xb)
		cout << dist - abs(b-xa) << endl;
	else cout << dist << endl;
}

int main(){
	#ifndef RAY
		//~ freopen("input.txt", "r", stdin);
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
