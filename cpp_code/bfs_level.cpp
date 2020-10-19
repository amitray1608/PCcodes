#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<ll>> G(1000);
bool vis[1000];
ll level[1000];


void bfs(ll s)
{
	queue<ll>Q;
	Q.push(s);
	level[s] = 0;	
	vis[s] = true;
	while(!Q.empty()){
		ll v = Q.front();
		cout << v << " ";
		Q.pop();
		for(ll i = 0; i<G[v].size(); i++)
		{
			if(vis[G[v][i]] == false)
			{
				level[G[v][i]] = level[v] + 1;
				Q.push(G[v][i]);
				vis[G[v][i]] = true; 
			}
			
		}
	}

}


int main(){
	memset(vis, 0, sizeof vis);
	int n, m;
	cin >> n >> m;
	for(ll i = 0; i<m; i++)	
	{
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	bfs(0);
	cout << endl << level[n-1] << endl;
return 0;
}
