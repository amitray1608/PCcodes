#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
	ll n;
	cin >> n;
	ll sum = 0, a[n];
	for (ll i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a+n);
    bool flag = true;
	if (sum % 2 != 0)
		flag = false;
	
	for (ll i = 0; i < n; i++){
		if (a[i] > sum / 2) {
			flag = false;
			    break;
		}
	}
    ( flag ) ? cout << "YES" : cout << "NO";
	
}
 
int main()
{
	
	    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
		ll t =1;
		//	cin >> t;
		while(t--)
		{
			solve();
		}
		return 0;
}
