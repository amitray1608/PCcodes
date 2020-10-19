#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>adj, adj2;

int main() {
	int n, m;
	cin >> n >> m;
	adj.resize(n);
	adj2.resize(n);
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj2[v].push_back(u);
	}
	int maxi = 0, maxi2 = 0;
	for(int i = 0; i < n; i++) {
		if(adj[i].size() == 0)
			maxi++;
		if(adj2[i].size() == 0)
			maxi2++;
	}
	cout << max(maxi, maxi2);
	return 0;
}
