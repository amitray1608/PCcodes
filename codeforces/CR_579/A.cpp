#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	ll n;
	cin >> n;
	ll a[n];
	for(ll i = 0; i<n; i++)
	cin >> a[i];
	
	bool flag = true;
	ll count = 0;
	for(ll i = 0; i<n-1; i++)
	{
			if(abs(a[i]-a[i+1]) != 1)
			count++;
	}
	if(count>1)
	flag = false;
	
	(flag) ? cout << "YES\n" : cout << "NO\n";
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
	cin >> t;
	while(t--)
	{
		solve();
	}
		return 0;
}
