	//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
vector<vector<pair<int, int>>>V(10);
const int INF = 100000000;
void dijkstra(int s, vector<int> &d, vector<int>&p){
		
	int n = V.size();
	d.assign(n, INF);
	p.assign(n, -1);
	vector<bool> vis(n, false);
	d[s] = 0;
	for(int i = 0; i < n; i++){
		int v = -1;
		for(int j = 0; j < n; j++){
			if(!vis[j] && (v == -1 || d[j] < d[v]))
				v = j;
		}
		if(d[v] == INF) break;
		
		vis[v] = true;
		for(auto edge : V[v]){
			int to = edge.first;
			int len = edge.second;
			if(d[v] + len < d[to]){
				d[to] = d[v] + len;
				p[to] = v;
			}
		}
	}
	
}

void solve(){
	int n, m;
	cin >> n >> m;
	while(m--){
		int x, y, z;
		cin >> x >> y >> z;
		V[x].push_back(make_pair(y, z));
		V[y].push_back(make_pair(x, z));
	}
	vector<int>d, p;
	dijkstra(1, d, p);
	for(int i = 1; i <= n; i++){
		cout << "1 to " << i << " " << d[i] << endl;
	}
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
	
