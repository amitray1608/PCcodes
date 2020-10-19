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
		 ll a, b, c, d;
		 cin >> a >> b >> c >> d;
		 if(c == d){
			if(a == b)
				cout << "YES";
			else
				cout << "NO";
		}else{
			ll dist = abs(c-d), s = abs(a-b);
			if(s % dist == 0)
				cout << "YES";
			else
				cout << "NO";
		}
		cout << endl;
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
