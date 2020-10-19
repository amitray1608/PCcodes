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
	int x, n, m;
	cin >> x >> n >> m;
	while ( x > 0 && n && x/2+10 < x){
		n--;
		x = x/2+10;
	}
	//int ans = x/(2*n);
	if(x <= (m*10))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
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
