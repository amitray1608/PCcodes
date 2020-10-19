//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
void solve(){
	int n, k, q;
	cin >> n >> k >> q;
	string s;
	cin >> s;
	int a[n] = {0};
	a[0] = (int)s[0]-'0';
	for(int i = 1; i < n; i++)
		a[i]+=a[i-1]+(int)(s[i]-'0')
	
	
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
