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
	ll n, x;
	cin >> n >> x;
	ll a[n], sum = 0;
	for(int i = 0; i<n; i++) {
		cin>>a[i];
		sum += a[i];
	}
	double given = 0;
	sort(a, a+n);
	for(int i=0; i<n; i++) {
		given = sum / (double)(n-i);
		if(given >= x) {
			cout << n-i << endl;
			return;
		}
		sum -= a[i];
	}
	cout << 0 << endl;	
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
	
