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
	int n, a, b, maxa = -1, maxb = -1;
	cin >> n >> a >> b;
	while(a--){
		int x;
		cin >> x;
		maxa = max(x, maxa);
	}
	while(b--){
		int x;
		cin >> x;
		maxb = max(x, maxb);
	}
	(maxa > maxb) ? cout << "YES\n" : cout << "NO\n";
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
	
