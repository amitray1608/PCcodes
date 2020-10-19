//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
ll aa[31];
void solve(){
	ll n;
	cin >> n;
	ll a = pow(2,n);
	for(int i = 1; i < n/2; i++)
		 a += pow(2, i);
	ll b=0;
	for(int i = n/2; i<n; i++)
		   b += pow(2,i);
	cout << abs(a-b) << endl;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		cin >> t;
		aa[1] = 2LL;
	for(int i = 2; i <= 30; i++) aa[i] = aa[i-1]*2LL;
		while(t--){
			solve();
		}
	return 0;
}	
