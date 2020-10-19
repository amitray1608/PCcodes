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
	int n = 5, count = 0, x, r = 0, c = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> x;
				if(x == 1)
					r = i, c = j; 
		}
	}
	count = abs(r-2) + abs(c-2);
	cout << count << endl;
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
