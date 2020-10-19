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
	int n;
	cin >> n;
	int a, b, c;
	cin >> a >> b >> c;
	vector<int>f(n);
	for(int i = 0; i < n; i++) 
		cin >> f[i];
	sort(f.begin(), f.end());
	ll ans = 0, x = 1000000000000000;
		for(int i = 0; i < n; i++){
				ans += c;
				ans += abs(a-f[i]);
				ans += abs(f[i]-b);
				x = min(x, ans);
				ans = 0;
		}
	cout << x << endl;
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
	
