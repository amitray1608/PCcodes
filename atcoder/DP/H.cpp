#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const int siz = 1e5 + 5;
vector <ll> edges[siz];
vector <ll> in_degree(siz);
int dist[siz];
bool vis[siz];
void solve();
ll mod = 1e9+7;
void solve()
{
	int h, w;
	cin >> h >> w;
	char block[h][w];
	
	for(int i= 0; i<h; i++)
			cin >> block[i];
			
	int dp[h][w];

	memset(dp, 0, sizeof dp);
	dp[0][0] = 1;
		
	for(int i = 0; i<h; i++)
	{
		for(int j = 0; j<w; j++)
		{
			if(i-1>=0 && block[i][j] == '.')
				dp[i][j] = (dp[i-1][j] + dp[i][j])%mod;
			if(j-1>=0 && block[i][j] == '.')
				dp[i][j] = (dp[i][j-1] + dp[i][j])%mod;
		}
	}
	cout << dp[h-1][w-1] << endl;
	
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
	
