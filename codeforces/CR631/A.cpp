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
	int n, x;
	cin >> n >> x;
	int a[n];
	int f[202] = {0};
	for(int i = 0; i < n; i++)
		cin >> a[i], f[a[i]] = 1;
	int ans = 0;
	for(int i = 1; i < 203; i++){
		if(f[i] == 1) {ans = i; continue;}
		if(f[i] == 0 && x == 0) break;
		f[i] = 1;
		ans = i;
		x--;
	}
	cout << ans << endl;
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
	
