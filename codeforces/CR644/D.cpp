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
		int n,k;
		cin >> n >> k;
		if(k >= n){
			cout << 1 << endl;
			return;
		}
		ll maxi = -1;
		for (ll i = 1; i <= sqrt(n); i++) { 
		  if (n%i == 0) {
				if (n/i == i){
					if(i <= k)
						maxi = max(maxi, i);
				}
				else{
					if((n/i) <= k)
						maxi = max(maxi, (n/i));
					if(i <= k)
						maxi = max(maxi, i);
				} 
		  }
		}
		cout << n/maxi << endl;
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
