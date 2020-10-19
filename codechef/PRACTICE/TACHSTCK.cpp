#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	ll n, k;
	cin >> n >> k;
	ll a[n];
	for(ll i = 0; i<n; i++)
	cin >> a[i];
	
	sort(a, a+n);
	ll count = 0, x;
	for(ll i = 0; i<n; i++)
	{
			if(abs(a[i] - a[i+1]) <= k)
				count++, i++;
	}
	cout << count << endl;	
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
