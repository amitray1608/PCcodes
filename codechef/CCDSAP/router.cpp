//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
vector<int>adj[100002];
vector<bool>vis(100002, 0);
vector<int>dis(100002, -1);
int n;
pair<int, int > bfs(int s){
	for(int  i = 0; i < n; i++) dis[i] = -1;
	queue<int>q;
	q.push(s);
	dis[s] = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(auto i : adj[x]){
			if(dis[i] == -1){
				q.push(i);
				dis[i] = dis[x] + 1; 
			}
		}
	}
	pair<int, int> p;
	p.first = 0, p.second = 0;
	for(int  i = 0; i < n; i++){
		if(p.second < dis[i])
			p.second = dis[i], p.first = i;
	} 
	return p;
}

pair<int, int>dfs(int s){
	
	
}

void solve(){
	//int n;
	cin >> n;
	for(int  i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	pair<int, int > ans = bfs(0);
	//cout << ans.first << " " << ans.second << endl;
	ans = bfs(ans.first);
	//cout << ans.first << " " << ans.second << endl;	
	cout << (ans.second) << endl;
	for(int  i = 0; i < n; i++)
	vis[i] = false, adj[i].clear(), dis[i] = -1;
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
	
