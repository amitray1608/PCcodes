//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
vector<vector<int>>G(10, vector<int>(10));

bool bipartite(int n){
	vector<int>side(n, -1);
	bool isbipatite = true;
	queue<int>q;
	for(int i = 0; i < n; i++){
		if(side[i] == -1){
				q.push(i);
				side[i] = 0;
				while(!q.empty()){
					int v = q.front();
					q.pop();
					for(int u : G[v]){
						if(side[u] == -1){
							side[u] = side[v]^1;
							q.push(u);
						}else{
							isbipatite &= side[u] != side[v];
						}
					}
				}
		}
	}
	return isbipatite;
}

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if(bipartite(n))
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main(){
	#ifndef RAY
		freopen("input.txt", "r", stdin);
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
	


