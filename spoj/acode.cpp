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
	while(true){
		string s;
		cin >> s;
		if(s[0] == '0'){
			break;
		}
		int n = s.size();
		int dp[n+1] = {0};
		dp[0] = 1;
		for(int i = 1; i<n; i++){
			int num=(s[i-1]-'0')*10;
         
         num+=s[i]-'0';
         
         /*checking for valid 1 digit number*/
         if(s[i]-'0')
         {
            dp[i]=dp[i-1];
         }   
         /*checking for two digit number*/
         if(num>9 && num<=26)   
         {
            dp[i]+=dp[i-2<0?0:i-2];
         }

		}
		cout << dp[n-1] << endl;
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
