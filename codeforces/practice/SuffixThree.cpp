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
	int n = (int)s.size();
	if(s.substr(n-2, n) == "po")
		cout << "FILIPINO\n";
	else if(s.substr(n-4, n) == "desu" || s.substr(n-4, n) == "masu")
		cout << "JAPANESE\n";
	else cout << "KOREAN\n";
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
