//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
ll pre[100];
void solve(){
	ll n;
	cin >> n;
	ll ans = 0, maxi = 1;
	while(n > 0){
		maxi = 1;
		if(((2*((maxi*(maxi+1)/2)))+(((maxi-1)*(maxi))/2)) > n){
			break;
		}
		while(((2*((maxi*(maxi+1)/2)))+(((maxi-1)*(maxi))/2)) <= n){
			maxi++;
		}
		maxi--;
		n = n-(2*((maxi*(maxi+1)/2)))-(((maxi-1)*(maxi))/2);
		ans++;
	}
	cout <<  ans << endl;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		cin >> t;
		//for(int i = 1; i < 100; i++){
			//ll x = (x*((3ll*x)+1))/2ll;
			//pre[i] = x;
		//}
		while(t--){
			solve();
		}
	return 0;
}	
	
