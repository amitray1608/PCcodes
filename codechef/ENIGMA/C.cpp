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
	int n, m, c;
	cin >> n >> m >> c;
	int s = 0, t = 0;
	while(n--){
		int p, y, x;
		cin >> x >> y >> p;
		if((y - (m*x) - c ) < 0)
			t += p;
		else
			s += p;
	}
	(s > t) ? cout << s: cout << t;
        cout << endl;
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
	
