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
	int a, b;
	cin >> a >> b;
	if(a > b)
		swap(a, b);
	ll ans = 0, x = 0, y = 0; 
	while(a < b){
		if(x < y)
			a+=1, x+=1, ans += x;
		else
			b-=1, y+=1, ans += y;
	}
	cout << ans << endl;
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
	
