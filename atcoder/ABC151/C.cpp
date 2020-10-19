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
	ll n;
	cin >> n;
	ll tp;
	cin >> tp;
	ll a[n+1], aa[n+1];
	memset(a, -1, sizeof a);
		memset(aa, 0, sizeof aa);
	while(tp--){
		string s;
		ll b;
		cin >> b >> s;
		if(s == "AC" && a[b] == -1) a[b] = 1;
		else if(a[b] == 1) continue;
		else aa[b]++;
	}
	ll count = 0, sum = 0;
	for(int i = 0; i <= n; i++){
		if(a[i] == 1)
			sum += aa[i], count++;
	}
	cout << count << " " << sum << endl;
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
	
