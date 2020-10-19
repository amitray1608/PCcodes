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
	int x, y, z;
	cin >> x >> y >> z;
	int a, b, c;
	cin >> a >> b >> c;
	if (a < x){
		cout << "NO" << endl;
		return ;
	}
	a -= x;
	if (a + b < y){
		cout << "NO" << endl;
		return;
	}
	if (a + b - y + c < z){
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
	
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
	
