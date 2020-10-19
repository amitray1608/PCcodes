#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n;
	cin >> n;
	ll a[n];
	for(ll i = 0; i<n; i++)
		cin >> a[i];
	
//	ll x = *min_element(a, a+n);
ll ans = 0;
		sort(a, a+n);
		for(ll i = 1; i<n; i++)
			ans += (a[i] - (a[i-1]+1));
		
		cout << ans << endl;
		return 0;
}
