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
	int n, m;
	cin >> n >> m;
	int a[m];
	for(int &i : a) cin >> i;
	sort(a, a+m);
	int ans = INT_MAX;
	for(int i = 0; i < m-n+1; i++){
		int mini = INT_MAX, maxi = INT_MIN;
		for(int j = i; j < i+n; j++)
			mini = min(mini, a[j]), maxi = max(maxi, a[j]);
		ans = min(ans, (maxi-mini));
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
		//cin >> t;
		while(t--){
			solve();
		}
	return 0;
}	
