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
	int n, k;
	cin >> n >> k;
	int a[26] = {0};
	string s;
	cin >> s;
	int tt = k;
	while(tt--){
		char x;
		cin >> x;
		a[x-'a'] = 1;
	}
	ll ans = 0, count = 0;
	for(int i = 0; i < n; i++){ 
		if(a[s[i] - 'a'] == 1)
			count++;
		else 
			ans += (count *(count+1)/2), count = 0;
	}
	ans += (count*(count+1)/2);
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
	
