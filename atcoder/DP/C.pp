#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int INF = 1e9 + 5;
void solve()
{
		int n;
		cin >> n;
		vector <int> h(n, 0);
		int k;
		cin >> k;
		for(int &x : h)
			cin >> x;
			
		vector <int> dp(n, INF);
		dp[0] = 0;
		for(int i = 0; i<n; i++)
		{
			for(int j = i+1; j<=i+k; j++)
			{
				if(j < n)
				{
					dp[j] = min(dp[j], dp[i] + abs(h[i]-h[j]));
				}
			}
		}
		
		cout << dp[n-1];
		
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
