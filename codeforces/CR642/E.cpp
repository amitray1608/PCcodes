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
	int a[n];
	ll sum = 0;
	for(int &i : a) cin >> i, sum+=i;
	ll count = (n*(n+1))/2, pre[n] = 0, suf[n] = 0;
	int p = 0, s = n-1;
	for(int i = 0; i < n; i++){
		if(i == 0)
			pre[i] = a[i], suf[n-i-1] = a[n-i-1];
		else{
			pre[i] = pre[i-1]+a[i];
			suf[n-i-1] = suf[n-i-2]+a[n-i-1];
		}
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
	
