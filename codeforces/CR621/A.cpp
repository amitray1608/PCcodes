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
		int n , d;
		cin >> n >> d;
		int  f , p;	
		//for(int i = 0 ; i < n ; i++){
		//cin >> a[i];
		//}
		for ( int i = 0; i < n; i++ ) {
			cin >> p ;
			if ( i == 0 ) {
				f = p;
				continue;
			}
			while ( p > 0 && d >= i ) {
				p--;
				d -= i;
				f++;
			}
		}
		cout << f << endl;
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
