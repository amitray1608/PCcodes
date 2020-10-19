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
	int a[n], b[n];
	for(int i = 0; i< n; i++) 
		cin >> a[i];
	for(int i = 0; i< n; i++) 
		cin >> b[i];
	int ans[m];
	memset(ans, -1, sizeof ans);
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++)
			if(a[j] == i+1){
				if(ans[i] == -1) 
					ans[i] = 0, ans[i] += b[j];
				else
					ans[i] += b[j];
			}
	}
	for(int i = 0; i < m; i++)
		if(ans[i] == -1)
			ans[i] = INT_MAX;
	sort(ans, ans+m);
	cout << ans[0] << endl;
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
