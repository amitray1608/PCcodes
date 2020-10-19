#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
void solve()
{
		ll n, w;
		cin >> n >> w;
			vector <ll> weight(n), value(n);
			
		for(ll i = 0; i<n; i++)
		{
			cin >> weight[i] << value[i];
		}	
		ll sum = 0;
		for(ll i : value)
			sum += i;
			
			vector <ll> dp(sum+1, INF);
			dp[0] = 0;
			
		for(ll i = 0; i<n; i++)
		{
			for()
			
		}
}

int main()
{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
	//	cin >> t
		while(t--)
		{
			solve();
		}
	return 0;
}
