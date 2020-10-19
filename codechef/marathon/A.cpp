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
	ll n, k;
	cin >> n >> k;
	ll a[n];
	ll sum = 0, maxi = 0;
	for(ll &i : a) cin >> i, sum += i, maxi = max(maxi, i);
	if(sum % k == 0 && maxi <= sum / k)
		cout << "YES\n";
	else
		cout <<  "NO\n";
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
