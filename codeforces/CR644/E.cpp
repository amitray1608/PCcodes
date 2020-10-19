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
	string s[n];
	for(int i=0; i < n; i++)
		cin >> s[i];
	int flag = 0;
	for(int i=0; i < n-1; i++)
		for(int j=0; j < n-1; j++)
			if(s[i][j]=='1' && (s[i+1][j]!='1' && s[i][j+1]!='1'))
			flag = 1;
	if(flag)
		cout << "NO" << endl;
	else
		cout << "YES"<< endl;	
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
