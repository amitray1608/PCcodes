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
		ll a, b;
		cin >> a >> b ; 
		if ( a > b ) {
			if (( a-b )%2 == 0 ) 
				cout << 1 << endl ; 
			else cout << 2 << endl ; 
		}
		else if ( b > a ) {
			if ( ( b-a )% 2 == 0 ) 
				cout << 2 << endl ; 
			else
				cout << 1 << endl ; 
		}
		else cout << 0 << endl ; 
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
