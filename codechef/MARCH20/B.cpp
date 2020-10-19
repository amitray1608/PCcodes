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
	int n, q; cin >> n >> q;
	int oc = 0;
	for (int i = 0; i < n; i++) {
		ll k; cin >> k;
		if (__builtin_popcountll(k) & 1) ++ oc;
	}
	for (int i = 0; i < q; i++) {
		int k; cin >> k;
		if (__builtin_popcount(k) & 1) cout << oc << ' ' << n - oc << "\n";
		else cout << n - oc << ' ' << oc << "\n";
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
