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
	int n;
	cin >> n;
	int x = 0, tot = 0;
	vector<int>a(n), b(n);
	for(int &i : a) cin >> i, x ^= i;
	for(int &i : b) cin >> i, x ^= i, tot ^= i;
	if(x != 0)
		cout << -1 << endl;
	else{
		deb(tot);
		deb(x);
		for(int i = 0; i < n; i++){
			int ans = a[i]^tot;
			cout << ans << " ";
			
		}
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
