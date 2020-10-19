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
	ll n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	if(s[k-1] != s[0]){
		cout << s[k-1] << endl;
		return;
	}
	cout << s[0];
	if(s[k] != s[n-1]){
		for(int i = k; i < n; i++)
			cout << s[i];
	}else{
		for(int i = 0; i < (n-k+k-1)/k; i++)
			cout << s[n-1];
	}
	cout << endl;	
	
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
