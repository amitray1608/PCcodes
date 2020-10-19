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

void dfs(int a)
{
	assert(!vis[a]);
	vis[a] = true;
	for(int b : edges[a])
	{
			dist[b] = max(dist[b], dist[a]+1);
			--in_degree[b];
			if(in_degree[b] == 0)
					dfs(b);
	}
	
	
}

void solve()
{
	int n, m;
	cin >> n >> m;
		while(m--)
		{
			int a, b;
			cin >> a >> b;
			edges[a].push_back(b);
			in_degree[b]++;
		}
		
		for(int i = 1; i<=n; i++){
				if(!vis[i] && in_degree[i] == 0)
					dfs(i);
		}
		int ans = 0;
		for(int i = 1; i<=n; i++)
			ans = max(ans, dist[i]);
			
		cout << ans << endl;
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
	
