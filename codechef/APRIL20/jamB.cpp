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
	int c = 0, n = s.size();
    string ans = "" ;
	for( int i =0; i < n; i++){
		int d = s[i] - '0';
		if(d < c){
			int left = c - d;
			while(left > 0){
				ans.push_back(')');
				left--;
			}
			ans.push_back(s[i]);
			c = d;
		}else{
			int left = d-c;
			while(left > 0){
				ans.push_back('(');
				left--;
			}
			ans.push_back(s[i]);
			c = d;
		}
	}

	while(c > 0){
		 ans.push_back(')');
			c--;
	}
    cout << ans << endl;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1, tt = 1;
		cin >> t;
		while(t--){
			cout << "Case #" << tt++ << ": ";
			solve();
		}
	return 0;
}	
