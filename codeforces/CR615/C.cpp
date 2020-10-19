//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
int factor(int n, int c);
void solve(){
        int n;
		cin >> n;
		int a = factor(n, 0);
		if(a == 0) {
			cout << "NO\n";
			return;
		}
		int b = n/a;
		int x = factor(a, b), y = factor(b, a);
		if(x) {
			cout << "YES\n" << a/x << " " << b << " " << x << "\n";
			return;
		}
		if(y) {
			cout << "YES\n" << a << " " << b/y << " " << y << "\n";
			return;
		}
		cout << "NO\n";
}
int factor(int n, int c) {
 
	for(int i=2; i*i <= n; i++) {
		if(n%i == 0 && c!=i && i*i!=n) return i;
	}
	return 0;
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
	
