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
	string s;
	cin >> s;
	ll n = s.length();
	s = " " + s;
	ll pre[n] = {0};
	for(int i = 1; i <= n; i++)
		pre[i] = pre[i-1] + (s[i] == '1');
	ll mini = min(pre[n], n - pre[n]);
	for(int i = 1; i <= n; i++)
		mini = min(mini, i - pre[i] + pre[n] - pre[i]);
	for(int i = n; i >= 1; i--)
		mini = min(mini, (n - i + 1) - (pre[n] - pre[i-1]) + pre[i-1]);
	cout << mini << endl;	
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
