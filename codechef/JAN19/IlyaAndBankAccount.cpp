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
	int len = s.length();
	if(s[0] == '-'){
		if(s[len-2] > s[len-1])
		swap(s[len-2], s[len-1]);
		if(s[1] == '0') cout << 0 << endl;
		else{
		for(int i = 0; i < len-1; i++)
			cout << s[i];
		}
	}else{
		cout << s << endl;
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
