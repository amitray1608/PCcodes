//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
vector<pair<int, int>>G[siz];
int vis[siz];
vector<int>order;
vector<int>dist(siz, INT_MAX);
typedef pair<int,int> pr;
int n, m;
void dijk(){
	priority_queue < pr, vector<pr>, greater<pr>>pq; 
	//~ memset(dist, INT_MAX, sizeof dist);
	memset(vis, false, sizeof vis);
	pq.push(make_pair(0, 1));
	dist[1] = 0;
	
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		for(auto x : G[u]){
			int v = x.first;
			int weight = x.second;
			if(dist[v] > dist[u]+weight){
				dist[v] = dist[u]+weight;
				order.push_back(weight);
				pq.push(make_pair(dist[v], v));
			}
		}
	}
}


void solve(){
		//~ int n, m;
		cin >> n >> m;
		dist[1] = 0;
		while(m--){
			int u, v, w;
			cin >> u >> v >> w;
			G[u].push_back(make_pair(v, w));
			G[v].push_back(make_pair(u, w));
		}
		dijk();
		int count = 0;
		sort(order.begin(), order.end());
	for(int i : order){
		count++;
		cout << i << " ";
		if(count == n-1) {break;}
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
