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
	ll a[n];
	for(ll &i : a) cin >> i;
	ll h[n] = {0}, sum = 0, ans = 0, maxi[n] = {0};
		for (int i = 0; i < n; i++) {
			sum = a[i];
		for(int j=0; j<n; j++)
			h[j] = a[j];
		for(int j = i-1; j >= 0; j--){
			if(h[j] > h[j+1])
				h[j] = h[j+1];
			sum += h[j];
		}
		for(int j= i+1 ; j < n; j++){
			if(h[j] > h[j-1]) 
				h[j] = h[j-1];
			sum += h[j];
		}
		if(sum > ans){
			ans = sum;
			for(int j = 0; j < n; j++) 
				maxi[j] = h[j];
		}
	}
	for (int i = 0; i < n; i++) {
		cout << maxi[i] << ' ';
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
		//cin >> t;
		while(t--){
			solve();
		}
	return 0;
}
