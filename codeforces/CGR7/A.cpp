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
	ll n;
		cin >> n;
	if(n == 1)
		cout << -1 << endl;
	else if(n == 2)
		cout << 23 << endl;
	else{
		//int p;
		//if(((n-1)*2) % 3 == 0)
			//p = n-1;
		//else
			//p = n-2;
			
		if ((n - 1) % 3 == 0) {
			for (int i = 0; i < n - 2; i++) 
				cout << 2;
			cout << 33;
		} else {
			for (int i = 0; i < n - 1; i++) 
				cout << 2;
			cout << 3;
		}
		cout << endl;
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
