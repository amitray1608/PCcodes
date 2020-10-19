#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
		ll n;
		cin >> n;
		ll C[n+1], Z[n+1]={0}, level[n+1]={0};
		
		for(int i = 1; i<=n; i++)
			cin >> C[i];
		for(int i = 1; i<=n; i++)
			cin >> Z[i];
			
		for(ll i = 1; i<=n; i++)
		{
			for(ll j = max(1LL, i-C[i]); j <= min(n, i+C[i]); j++)
			level[j]++;
		}
		
		sort(level, level+n+1);
		sort(Z, Z+n+1);
		
		
		bool flag = true;
		for(ll i = 1; i<=n; i++)
			if(Z[i] != level[i]) flag = false;
			
		(flag) ? cout << "YES\n" : cout << "NO\n";
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
		return 0;
}
