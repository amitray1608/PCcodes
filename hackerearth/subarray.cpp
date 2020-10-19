#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll t;
	cin >> t;
	while(t--){
	ll n, k;
	cin >> n >> k;
	ll a[n];
	for(int i = 0; i<n; i++)
	cin >> a[i];
	
	ll pref[n+1];
	pref[0] = 0;
	for(int i = 1; i<=n; i++)
		pref[i] = pref[i-1]+a[i-1], cout << pref[i] << " ";
		
		cout << endl;

	sort(pref, pref+n+1);
	ll ans = 0;
	
	for(ll i = 0; i<n; i++){
	ll val = pref[i]+k;
	cout << val << " ";
	ll cal = upper_bound(pref, pref+n+1, val) - pref;
	cout << cal << " ";
	ans +=((n+1)-cal);
	cout << ans << endl;
	}
	cout << ans << endl;

	}
}

