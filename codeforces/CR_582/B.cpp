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
	}
	
	ll count =  0;
	ll mini = a[n-1];
	for(ll i = n-2; i>=0; i--)
	{
		if(a[i]>mini)
		count++;
		
		else 
		mini = min(mini, a[i]);
	}
	
	cout << count << endl;
}

int main()
{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
		cin >> t;
		while(t--)
		{
			solve();
		}
	return 0;
}
