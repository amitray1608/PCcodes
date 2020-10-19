//"Make it work, make it right, make it fast." - Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
vector<vector<int>>adj;
vector<int>ans;
void solve(){
	int n, m;
	cin >> n >> m;
	adj.resize(n);
	vector<int>indeg(n, 0);
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		indeg[v]++;
	}
	set<int>q;
	for(int i = 0; i < n; i++)
		if(indeg[i] == 0)
			q.insert(i);
	int count = 0;
	while(!q.empty()){
		int x = *q.begin();
		q.erase(q.begin());
		ans.push_back(x);
		for(int i : adj[x])
			if(--indeg[i] == 0)
				q.insert(i);
		count++;
	}
	//reverse(ans.begin(), ans.end());
	if(count != n)
		cout << "Sandro fails." << endl;
	else
		for(int i = 0; i < n; i++) 	
			cout << ans[i]+1 << " ";
	
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
