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
	int k, n;
	int x;
	int prev, tmp, ans = 0;
	cin >> k >> n;
	cin >> x;
	prev = x;
	for(int i = 1; i < n; i++){
		cin >> tmp;
		ans = max(ans, tmp - prev);
		prev = tmp;
	}
	ans = max(ans, x + (k - prev));
	cout << k - ans << "\n";
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
