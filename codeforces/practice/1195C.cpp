#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector <ll> a(n), b(n);
	for(ll &x: a)
		cin >> x;
	for(ll &x: b)
		cin >> x;
	ll dp[2][n+1];
	dp[0][0] = dp[1][0] = 0;
	
		for(ll j = 1; j<=n; j++)
		{
				dp[0][j] = max(dp[0][j-1], dp[1][j-1]+a[j-1]);
				dp[1][j] = max(dp[1][j-1], dp[0][j-1]+b[j-1]);
		}	
		cout << max(dp[0][n], dp[1][n]);
		return 0;
}
