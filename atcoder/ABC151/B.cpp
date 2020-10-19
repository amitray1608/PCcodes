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
	int n, m, k;
	cin >> n >> k >> m;
	int a[n], sum = 0;
	for(int i = 0; i < n-1; i++){
		cin >> a[i];
		sum += a[i];
	}
	int x = m*n; 
	if((sum+k) < x)
		cout << -1 << endl;
	else 
	cout << max(0, x-sum) << endl;
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
	
