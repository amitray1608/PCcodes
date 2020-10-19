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
    int u, v; 
    cin >> u >> v;
    if (u > v|| (~u&1 && v&1)|| (u&1 && ~v&1)) {
		cout << "-1" << endl;
		return;
    } 
	if (u == v) {
		cout << u << endl;
		return;
	}
	int a = (v - u)/ 2;
	int x = v - (a+a);
	if (a+x == (x^a)) {
		cout << 2 << endl;
		cout << a << " "<< a+x << endl;
	} else {
		cout << 3 << endl;
		cout << a << " " << a << " " << x << endl;
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
