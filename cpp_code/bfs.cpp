#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector< vector<ll> >G(1000);
bool vis[10000];
void bfs(ll s)
{
	queue<ll>q;
	q.push(s);
	vis[s]= true;
	while(!q.empty())
	{
		ll v = q.front();
		cout << v << " ";
		q.pop();
		for(ll i = 0; i< G[v].size(); i++)
		{
			if(vis[G[v][i]] == false)
			{
				q.push(G[v][i]);
				vis[G[v][i]] = true;

			}
		}
	}

}

int main(){
	memset(vis, 0, sizeof vis);
	int n, m;
	cin >> n >> m;
	for(int i =0; i<m; i++)
	{
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
		
	}
	bfs(2);
return 0;
}

