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
	ll h, c, t;
	cin >> h >> c >> t;
	if(t == h) {
		cout << 1 << endl;
		return;
	}
	if (h - t == t - c) {
		cout << 2 << endl;
		return;
	}
	double y = (t - c) / (double)(h - t);
	double x = (h - t)/(double)(2*t-h-c);
	ll low = (ll)x, high = x+1;
	double vol = abs(((low + 1) / (double)low) - y);
	double voll = abs(((high + 1) / (double)high) - y);
	if (voll < vol)
		cout << 2 * high + 1 << endl;
	else
		cout << 2 * low + 1 << endl;
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
