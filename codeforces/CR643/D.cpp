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
	int n, s;
	cin >> n >> s;
	if (2*n <= s){
		cout << "YES" << '\n';
		for (int i = 0; i < n-1; i++){
			cout << 2  << ' ';
			s -= 2;
		}
		cout << s << endl;
		cout << 1;
	}
	else {
		cout << "NO";
	}	
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
