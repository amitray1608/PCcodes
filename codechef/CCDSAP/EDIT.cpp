//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
int dp[1003];
bool iscap(char c){
	if(c >= 'A' && c <= 'Z')
		return true;
	else
		return false;
}
bool issmall(char c){
	if(c >= 'a' && c <= 'z')
		return true;
	else
		return false;
}
int rec(string s, int n, int count){
	if(n == 0)
		return 0;
	if(dp[n] != -1) return dp[n];
	if(iscap(s[n]) and issmall(s[n-1]))
		int ans = rec(s, n-2,)
}

void solve(){
	string s;
	cin >> s;
	memset(dp, -1, sizeof dp);
	int n = (int)s.size();
	int ans = rec(s, n-1, 0);
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
