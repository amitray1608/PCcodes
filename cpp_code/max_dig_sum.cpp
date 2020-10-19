#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	ll n;
	cin >> n;
	vector <ll> a(n);
	
	for(ll & i : a)
		cin >> i;
	
	map <ll, vector<ll> > check;
	for(ll i = 0; i<n; i++)
	{
		ll tmp = a[i], sum = 0;
		while(tmp > 0)
		{
			sum += tmp%10;
			tmp /= 10;
		}	
		check[sum].push_back(a[i]);
	}
	ll maxi = -1;
	for(auto itr = check.begin(); itr != check.end(); itr++)
	{
		if(itr->second. size() > 1)
		{
			vector <ll> v(itr->second.begin(), itr->second.end());
			
			for(ll i = 0; i< (ll)v.size()-1; i++)
			{
				for(ll j = i+1; j <(ll) v.size(); j++)
				{
					maxi = max(maxi, v[i]+v[j]);
				}
			} 
		}
	}
	cout << maxi << endl;
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
	
