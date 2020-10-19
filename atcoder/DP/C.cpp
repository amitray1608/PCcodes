#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int INF = 1e9 + 5;
void solve()
{
		int n;
		cin >> n;
		vector <int> dp(3, 0);
			for(int days = 0; days < n; days++)
			{
				vector <int> c(3);
						vector <int> new_dp(3, 0);

				for(int i = 0; i<3; i++)
					cin >> c[i];
					
				for(int i= 0; i<3; i++)
				{
					for(int j = 0; j <3; j++)
					{
						if(i!=j)
						{
							new_dp[j] = max(new_dp[j], dp[i]+c[j]);
						}
					}
				}
				dp = new_dp;
					
			}
			
		cout << max(dp[0], max(dp[1], dp[2]));
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
