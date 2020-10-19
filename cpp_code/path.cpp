#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<ll>>G(10000);
bool vis[10000];

bool path(int s, int e){
	
	if(s == e)
		return true;
	queue<ll>Q;
	Q.push(s);
	vis[s] = true;	
	while(!Q.empty())
	{
		int x = Q.front();
		Q.pop();
		cout << x << " ";
	for(int i = 0; i<G[x].size(); i++)
		{
		
		if(G[x][i] == e)
			return true;	
			if(vis[G[x][i]] == false)
			{
				Q.push(G[x][i]);
				vis[G[x][i]] = true;
			}
		}
	}
return false;
}


int main(){
	int n, m;
	cin >> n >> m;
	memset(vis, false, sizeof vis);
	for(int i = 0; i<m; i++)
	{
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		//G[v].push_back(u);
	}
	int s, e;
	cin >> s >> e;
	(path(s, e)) ? cout << "Found the path :\n" : cout << "Not found.\n";
return 0;
}
