//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
vector<int> adj[200003];
vector<vector<int>> parent;
vector<int>depth;
int n, d;

int walk(int i, int k){
	for(int j = 0; j <= d && i != -1; j++)
		if(((1<<j) & k) > 0)
			i = parent[j][i];
	return i;
}

int lca(int i, int j){
	if(depth[i] > depth[j])
		i = walk(i, depth[i]-depth[j]);
	if(depth[j] > depth[i])
		j = walk(j, depth[j]-depth[i]);
	if(i == j)
		return i;
	for(int ii = d; ii >= 0; ii--)
		if(parent[ii][i] != parent[ii][j])
			i = parent[ii][i], j = parent[ii][j];
	return parent[0][i];
}
int dist(int i, int j){
	return depth[i] + depth[j] - 2*depth[lca(i, j)];
}

void bfs(){
	bool vis[n];
	memset(vis, 0, sizeof vis);
	queue<int>q;
	q.push(0);
	vis[0] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int i : adj[x])if(!vis[i]){
			vis[i] = true;
			q.push(i);
			depth[i] = depth[x]+1;
		}
	}
	for(int i = 1; i <= d; i++){
		for(int j = 0; j < n; j++){
			int mid = parent[i-1][j];
			if(mid != -1)
				parent[i][j] = parent[i-1][mid];
		}
	}
}

void solve(){
	cin >> n;
	//adj.resize(n);
	for(int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	d = ceil(log2(n));
	parent.resize(d);
	for(int i = 0; i < d; i++)
		parent[i].assign(n, -1);
	depth.resize(n);
	//bfs();
	ll ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = i+i; j <= n; i++)
			ans += dist(i-1, j-1)+1;
	cout << ans << endl;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		//cin >> t;
		while(t--){
			solve();
		}
	return 0;
}
