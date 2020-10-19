#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	ll n;
	cin >> n;
	ll a[n];
	for(ll i = 0; i<=2*n; i++)
		a[i]= i;

	if(~n%2)
	{
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	bool x = true;
	for(ll i = 2*n; i>=n; i--)
	{
		if(x)
			continue;
		cout << i 
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
	//cin >> t;
	while(t--)
	{
		solve();
	}
		return 0;
}
