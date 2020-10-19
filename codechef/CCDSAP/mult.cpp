//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
int siz = 1e8+1;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve(){
	int n;
	cin >> n;
	vector<ll> A(n);
	for (int i = 0; i < n; ++i)
	{
		ll a;
		cin >> a;
 
		if (a == 0LL)
		{
			cout << 0 << endl;
			return;
		}
		A[i] = a;
	}
 
	ll ans = A[0];
	ll mx = 1'000'000'000'000'000'000;
	for (int i = 1; i < n; ++i)
	{
		if (ans * A[i] > mx || ans > mx/A[i])
		{
			ans = -1;
			break ;
		}
		ans *= A[i];
	}
	cout << ans << endl;
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
