//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
const int inf = INT_MAX;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
void solve()
{
	int n, c;
	cin >> n >> c;
	int dp[2][1001];
	int st[n], ele[n];
	
	for(int i = 0; i <n-1; i++)
		cin >> st[i];
	
	for(int i = 0; i<n-1; i++)
		cin >> ele[i];
	
	for(int i = 0; i<n; i++)
		dp[0][i] = inf, dp[1][i] = inf;
		
	dp[0][0] = 0, dp[1][0] = c;
	//dp[0][0] = 0, dp[1][0] = 0;
	for(int i = 0; i<n-1; i++){
		dp[0][i+1] = min(dp[0][i+1], dp[1][i]+st[i]);
		dp[0][i+1] = min(dp[0][i+1], dp[0][i]+st[i]);
		dp[1][i+1] = min(dp[1][i+1], dp[1][i]+ele[i]);
		dp[1][i+1] = min(dp[1][i+1], dp[0][i]+ele[i]+c);
	}
	
	for(int i = 0; i<n; i++)
		cout << min(dp[0][i], dp[1][i]) << " ";
		
	cout << endl;
	
}

int main()
{
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
	//cin >> t;
		while(t--)
		{
			solve();
		}
	return 0;
}
	
