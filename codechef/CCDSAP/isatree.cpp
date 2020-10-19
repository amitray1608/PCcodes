//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
vector<vector<int>>adj;
bool vis[10002] = {false};
int dfs(int s){
	int count = 1;
	vis[s] = true;
	for(int u : adj[s]){
		 if(!vis[u]){
			count += dfs(u);
		} 
	}
	return count;
}

void solve(){
	int n, m;
	cin >> n >> m;
	adj.resize(n+1);
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);		
	}
	int count = dfs(1);
	if(n == m+1 && count == n)
		cout << "YES" << endl;
	else 
		cout << "NO" << endl;
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
