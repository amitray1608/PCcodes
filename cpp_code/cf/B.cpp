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
	string s, t = "";
	cin >> s;
	int n = s.size();
	int flag = 0, i;
	for(i = 1 ; i < n; i++){
		if(s[i] != s[i-1])
		flag = 1;
	}
	if(s[i-1] != s[0]) flag = 1;
	if(flag == 0){
		cout << s << endl;
        return;
    }
	else{
		for(i=1; i < n; i++){
			if(s[i] == s[i-1]){
				if(s[i-1] == '0')
					t = t+s[i-1] + "1";
			else
				t = t+s[i-1] + "0";
			}
			else{
				t += s[i-1];
			}
		}
 
			t += s[n-1];
		cout << t << endl;
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
