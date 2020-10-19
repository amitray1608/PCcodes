#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const ll siz = 1e5 + 5;
#define deb(x) cout << #x << " = " << x << endl;
vector< vector <ll> > G(siz);
bool vis[siz];
void dfs(ll src)
{
		
}

void solve()
{
	ll n, m;
	cin >> n >> m;
	memset(vis, false, sizeof vis);
	while(m--)
	{
		ll u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1);
	
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
	
