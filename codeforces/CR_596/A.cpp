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
	if(a == b)
		cout << a << 0 << " " << b << 1 << endl;
	else if(a + 1 == b)
		cout << a << 9 << " " << b << 0 << endl;
	else if(a == 9 && b == 1)
		cout << 99 << " " << 100 << endl;
	else 
		cout << -1 << endl;
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
