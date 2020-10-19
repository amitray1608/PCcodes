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
	vector<string>s(n);
	int at[n];
	memset(at, -1, sizeof at);
	for(int i = 0; i < n; i++) cin >> s[i];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(s[i][j] == '1')
				at[i] = j;
		}
	}
	for(int i : at) cout << i << " ";
	cout << endl;
	int ans = 0;
	for(int i = 0; i < n; i++){
		int l = at[i], h = at[i];
		for(int j = i; j < n; j++){
			l = min(l, at[j]);
			h = max(h, at[j]);
			ans += (int)(j-i == h-l);
			if(j-i == h-l){
				deb(j);
				deb(i);
				deb(l);
				deb(h);
			}
			cout << endl;
		}
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
