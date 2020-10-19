#include<bits/stdc++.h>
using namespace std;
//vector<vector<pair<int, int>>>adj;
#define deb(x) cout << #x << " " << x << endl;
int inf = 1e9;
int n, m;
bool flag = false;
struct edge{
	int u, v, c;
};
vector<edge>adj;

void bellman_(int s){
	vector<int>dis(n, inf);
	dis[s] = 0;
	//retrieve path
	vector<int>p(n, -1);
	for(;;){
		bool any = false;
		for(int i = 0; i < m; i++){
			if(dis[adj[i].v] > dis[adj[i].u] + adj[i].c){
				dis[adj[i].v] = dis[adj[i].u] + adj[i].c;
				p[adj[i].v] = adj[i].u;
				any = true;
			}
		}
			if(!any) break;
	}
	for(int i = 0; i < n; i++)
		cout << dis[i] <<  " ";
	cout << endl;
	vector<int>path;
	for(int i = 2; i != -1; i = p[i])
		path.push_back(i);
	reverse(path.begin(), path.end());
	for(int i : path)
		cout << i << " ";
}

void bellman(int s){
	vector<int>dis(n, inf);
	vector<bool>vis(n, false);
	dis[s] = 0;
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < m; j++)
			if(dis[adj[j].u] < inf)
				dis[adj[j].v] = min(dis[adj[j].v], dis[adj[j].u]+adj[j].c);
	}
	for(int i : dis)
		cout << i << ' ';
	cout << endl;
}
void solve(){
	//int n, m;
	cin >> n >> m;
	adj.resize(m);
	for(int i = 0; i < m; i++){
		cin >> adj[i].u >> adj[i].v >> adj[i].c;
	}
	bellman_(0);
	
}

int main(){
	int t = 1;
	//cin >> t;
	while(t--)
		solve();
	return 0;
}
/*
4 5
0 3 1
0 2 3
2 1 4
3 2 1
0 1 8
*/
