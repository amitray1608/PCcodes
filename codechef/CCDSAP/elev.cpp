//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
const int inf = 1e9;
vector<vector<pair<int, int>>>adj;
int f, s, g, d, u;
void listt(){
	adj.resize(f+1);
	queue<int>q;
	q.push(s);
	bool vis[f+1];
	memset(vis, 0, sizeof vis);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		if(!vis[x]){
			int costu = 1, costd = 1;
			int up = (x+u);
			int dw = (x-d);
			if(x+u <= f)
			adj[x].push_back({costu, up}), q.push(up);
			if(x-d >= 1)
			adj[x].push_back({costd, dw}), q.push(dw);
			vis[x] = true;
		}
	}
	//for(int i = 1; i <= f; i++){
		//for(auto ii : adj[i])
			//cout << i << " " << ii.second << " " << ii.first << endl;
		
	//}
}

void solve(){
	cin >> f >> s >> g >> u >> d;
	listt();
	vector<int>dis(f+1, inf);
	vector<bool>vis(f+1, false);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	dis[s] = 0;
	pq.push(make_pair(0, s));
	if(s == g) {cout << 0 << endl; return;}
	while(!pq.empty()){
		int uu = pq.top().second;
		pq.pop();
		vis[uu] = true;
		for(auto &i : adj[uu]){
			int v = i.second, x = i.first;
			if(!vis[v] && dis[v] > dis[uu] + x){
				dis[v] = dis[uu]+x;
				pq.push(make_pair(dis[v], v));
			}
		}
	}
	//for(int i = 0; i  < n; i++)
	if(dis[g] >= inf)
		cout << "use the stairs" << endl;
	else
		cout << dis[g] << endl;
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
			//cout << t << endl;
		}
	return 0;
}	
