//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
vector<int>adj[2001];
vector<int>vis(2001);
int male = 1, female = -1, sx = 0;

bool dfs(int s){
	bool ans = true;
	for(auto i : adj[s]){
		int v = i;
		if(vis[v] == vis[s]) return false;
		if(vis[v] == sx){
			vis[v] = -vis[s];
			ans = ans and dfs(v);
		}
	}
	return ans;
}

void solve(){
	int n, m;
	cin >> n >> m;
	for(int  i = 0; i < m; i++){
		int u, v;
		cin >> u >> v ;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bool ans = true;
	for(int i = 1; i <= n; i++){
		if(vis[i] == sx)
			vis[i] = male, ans = ans and dfs(i);
	}
	if(!ans)
		cout << "Suspicious bugs found!\n";
	else
		cout << "No suspicious bugs found!\n";
	
	for(int i = 1; i < n+1; i++)
		vis[i] = 0, adj[i].clear();
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		cin >> t;
		int x = 1;
		while(t--){
			cout << "Scenario #" << x++ << ":\n";
			solve();
		}
	return 0;
}	
