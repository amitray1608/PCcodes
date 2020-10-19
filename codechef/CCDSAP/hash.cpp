//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 163;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve(){
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	int p = 29;
	int pre[n] = {0}, suff[n] = {0}, a[n] = {0};
	for(int i = 0; i < n; i++){
		int x = pow(p, (i+1));
		int c = s[i]-'a'+1;
			pre[i] = (c*x)%MOD;
	}
	pre[0] = a[0];
	for(int i = 1; i < n; i++){
		pre[i] = pre[i-1] + a[i];
	}
	suff[n-1] = a[n-1];
	for(int i = n-2; i >= 0; i--){
		suff[i] = suff[i+1] + a[i];
	}
	while(q--){
		int l, r;
		cin >> l >> r;
		l--, r--;
		int pp = pre[r] - pre[l-1];
		int ss = suff[l] - suff[r+1];
		if(pp == ss)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
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
