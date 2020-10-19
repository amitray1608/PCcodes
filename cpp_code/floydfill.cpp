#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int dist[n+1][n+1] = {0};
void floyd(vector<vector<int>>&G, int n){
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			dist[i][j] = G[i][j];
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(dist[i][j] > G[i][k]+G[k][j])
					dist[i][j] = G[i][k]+G[k][j];
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++)
			if(dist[i][j] == inf)
				cout << "inf ";
			else
				cout << dist[i][j] << ' ';
		cout << endl;
	}
}
void solve(){
	int n, m, b;
	cin >> n >> m >> b;
	vector<vector<int>>G(n+1, vector<int>(n+1, 0));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++)
			if(i!=j) G[i][j] = inf; 
	}
	for(int i = 0; i < m; i++){
		int u, v, x;
		cin >> u >> v >> x;
		G[u][v] = x;
		G[v][u] = x;
	}
	floyd(G, n);
	meset(dist, 0, sizeof dist);
	int z;
	cin >> z;
	int a[z][3], i = 0;
	while(i < z){
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		i++;
	}
	int dp[]
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--)
		solve();
}
