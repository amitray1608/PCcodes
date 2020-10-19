#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int INF = 1e9 + 5;

void maxself(ll & a, ll b)
{
		a = max(a, b);
}

void solve()
{
		ll n, w;
		cin >> n >> w;
		vector <ll> dp(w+1);
		for(int i = 0; i<n; i++)
		{
			ll ww, val;
			cin >> ww >> val;
			cout << endl;
			for(ll j = w-ww; j>=0; j--)
			{
				maxself(dp[ww+j], dp[j]+val);
			}
			
				for(ll k = 0; k<=w; k++)
					cout << dp[k] << " ";	
					cout << endl;
			
		}
		ll ans = 0;
		for(ll i = 0; i<=w; i++)
			maxself(ans, dp[i]);
		
		cout << ans ;
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
