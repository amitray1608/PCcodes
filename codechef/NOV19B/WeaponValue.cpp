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
	int res[10] = { 0 };
	for(int i  = 0; i<n; i++){
		string s;
		cin >> s;
		for(int j = 0; j < 10; j++) res[j] ^= (int)(s[j] - '0'); 
	}
	int count = 0;
	count = accumulate(res, res+10, count);
	cout << count << endl;
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
