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
	int k;
	cin >> k;
	string s;
	cin >> s;
	int len = s.length();
	int count = 0;
	for(char c : s)
		if(c == '1')
			count++;
	if(count < k)
		cout << 0 << endl;
	else{
		ll ans = 0;
		for(int i = 0; i < len; i++){
			if(s[i] == '1')
				ans += ((i+1)*(i))/2;
		}
		cout << ans << endl;
	}
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
