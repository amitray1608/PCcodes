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
	while(n--){
		string s;
		cin >> s; 
		sort(s.begin(), s.end());
		bool flag = true;
		//cout << s << endl;
		for(int i = 0; i<(int)s.size()-1; i++){
			if(s[i]+1 == s[i+1]) continue;
			
			else {flag = false; break;}
		}
		(flag) ? cout << "Yes\n" : cout << "No\n";
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
