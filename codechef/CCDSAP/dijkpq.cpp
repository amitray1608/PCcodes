#include<bits/stdc++.h>
using namespace std;
int inf = INT_MAX;
vector<vector<pair<int, int>>>adj;
vector<int>p, dist;
vector<bool>vis;
int s, d;
bool spfa(int n)
	dist.assign(n, inf);
	vis.assign(n, false);
	p.assign(n, -1);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	dist[0] = 0;
	p[0] = -1;
	pq.push(make_pair(0, 0));
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		if(d == u)
			return true;
		vis[u] = true;
		for(auto &i : adj[u]){
			int v = i.first, x = i.second;
			if(!vis[v] && dist[u] + x < dist[v]){
				dist[v] = dist[u]+x;
				pq.push(make_pair(dist[v], v));
				p[v] = u;
			}
		}
	}
	return false;
}

void solve(){
	int n, m;
	cin >> n >> m;
	adj.resize(n+2);
	for(int i = 0; i < m; i++){	
		int u, v, x;
		cin >> u >> v >> x;
		u--, v--;
			adj[u].push_back(make_pair(v, x));
			adj[v].push_back(make_pair(u, x));
		}
		s = 0, d = n-1;
	if(spfa(n)){
		vector<int>path;
		for(int i = n-1; i != -1; i = p[i])
			path.push_back(i);
		reverse(path.begin(), path.end());
		for(int i : path)
			cout << i+1 << " ";
	}else
		cout << -1 << endl;
}

int main(){
	int t = 1;
	//cin >> t;
	while(t--)
		solve();
	return 0;
}
