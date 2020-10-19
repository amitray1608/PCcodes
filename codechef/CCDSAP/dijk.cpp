#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>>adj;
#define deb(x) cout << #x << " " << x << endl;
int s, d;
int inf = 1e9;
bool flag = false;
pair<vector<int>, int> dijkstras(int n){
	vector<int>dis(n, inf);
	vector<bool>vis(n, false);
	vector<int>p(n, -1);
	dis[s] = 0;
	pair<vector<int>, int>ans;
	//cout << "of" << endl;
	for(int i = 0; i < n; i++){
		int k = -1, m = inf;
		for(int j = 0; j < n; j++){
			if(!vis[j] && (k == -1 || dis[j] < m))
				k = j, m = dis[j];
		}
		//deb(k);
		if(dis[k] == inf)
        break;
        if(k == d)
			flag = true;
		vis[k] = true;
		for(int it = 0; it < (int)adj[k].size(); it++){
			int u = adj[k][it].first;
			int cost = adj[k][it].second;
			if(!vis[u] && dis[u] > dis[k]+cost){
				dis[u] = dis[k]+cost;
				p[u] = k;
			}
		}
	}
	vector<int>ss;
	for(int i = d; i != s; i = p[i]){
		ss.push_back(i);
	}
	ss.push_back(s);
	reverse(ss.begin(), ss.end());
	ans.first = ss;
	ans.second = dis[d];
	return ans;
}

void solve(){
	int n, m;
	cin >> n >> m;
	adj.resize(n);
	for(int i = 0; i < m; i++){	
		int u, v, x;
		cin >> u >> v >> x;
		u--, v--;
			adj[u].push_back(make_pair(v, x));
			adj[v].push_back(make_pair(u, x));
		}
	s = 0, d = n-1;
	//cout << endl;
	//for(auto i : adj){
		//for(auto xx : i)
			//cout << xx.first << " " << xx.second << endl;
		//cout << endl; 
	//}
	pair<vector<int>, int> p = dijkstras(n);
	//cout << p.second << endl;
	if(!flag)
		cout << -1;
	else{
	for(int i = 0; i < (int)p.first.size(); i++)
		cout << p.first[i] + 1<< " ";
	}
	//cout << endl;
	adj.clear();
}

int main(){
	int t = 1;
	//cin >> t;
	while(t--)
		solve();
	return 0;
}
/*
2
5
0 3 2 0 0
3 0 5 3 0
2 5 0 0 20
0 3 0 0 4
0 0 20 4 0
0 4
5
0 3 2 0 0
3 0 5 3 0
2 5 0 0 20
0 3 0 0 4
0 0 20 4 0
0 4
*/
