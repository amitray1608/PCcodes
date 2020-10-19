//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
vector<int>adj[10002];
vector<bool>vis(10002, 0);
vector<int>path(10002, -1);
ll dfs(int n, int s, int d){
	if(s == d) return 1;
	if(path[s] != -1) return path[s];
	vis[s] = true;
	ll ans = 0;
	for(auto i : adj[s]){
			ans  += dfs(n, (int)i, d);
			ans %= MOD;
	}
	path[s] = ans;
	return path[s];
}

void solve(){
	int n, m, s, d;
	cin >> n >> m >> s >> d;
	for(int  i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	int ans = dfs(n, s, d);
	//for(int i = 1; i <= n; i++)
	//cout << path[i] << " ";
	//cout << endl;
	cout << ans << endl;
	for(int  i = 0; i <= n; i++)
	vis[i] = false, adj[i].clear(), path[i] = -1;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		cin >> t;
		while(t--){
			solve();
		}
	return 0;
}	
	
