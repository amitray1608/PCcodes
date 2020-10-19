#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;

void solve()
{
		ll n;
			cin>>n;
	ll a[n];
	ll o =0, e=0;
	for(ll i=0;i<n;i++){
		cin>>a[i];
		if(a[i]%2==0)
			e++;
		else
			o++;
	}
	ll count = min(e, o);
	cout << count;
}

int main()
{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
		//cin >> t;
		while(t--)
		{
			solve();
		}
	return 0;
}
