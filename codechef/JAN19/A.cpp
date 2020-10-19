//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		cin >> t;
		while(t--){
				int n;
		cin >> n;
		ll once = 1;
			
		ll num = ((ll)2 * once);
		ll a, b, c, d, e;
		cin >> a;
		num +=  a;
		cout << num << endl;
		cout.flush(); 
		cin >> c;
		b = (ll)(once - c);
		cout << b << endl;
		cout.flush(); 
		cin >> e;
		d = (ll)(once - e);
		cout << d << endl;
		cout.flush();
		int verd;
		cin >> verd;
		if(verd == -1) return 0;
		else continue;
		}
	return 0;
}
