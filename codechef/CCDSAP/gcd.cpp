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
	ll a;
	cin >> a;
	string s;
	cin >> s;
	ll mod = 0;
	if(s == "0")
		cout << a << endl;	
	else if(a == 0)
		cout << s << endl;
	else{
		for(int i = 0; i < (int)s.size(); i++){
			mod = (10*mod + s[i] - '0')%a;
		}
		cout << __gcd(a, mod) << endl;
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
