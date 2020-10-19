#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef double dd;
const int MOD = 1e9 + 7;
const int MAXN = 100001;

int nodes = 0, subtree[MAXN];
set<int> g[MAXN];
char ans[MAXN];

void dfs(int u, int par) {
	nodes++;
	subtree[u] = 1;
	for(auto &it:g[u]) {
		if(it == par)
			continue;
		dfs(it, u);
		subtree[u] += subtree[it];
	}
}

int centroid(int u, int par) {
	for(auto &it : g[u]) {
		if(it == par)
			continue;
		if(subtree[it] > (nodes >> 1))
			return centroid(it, u);
	}
	return u;
}

void decompose(int u, char alpha) {
	nodes = 0;
	dfs(u, u);
	int node = centroid(u, u);
	ans[node] = alpha;
	for(auto &it : g[node]) {
		g[it].erase(node);
		decompose(it, alpha+1);
	}
}
void solve(){
  int n; 
  cin >> n;
  for(int i = 1; i < n; ++i) {
    int u, v; 
    cin >> u >> v;
    g[u].insert(v);
    g[v].insert(u);
  }
  decompose(1, 'A');
  for(int i = 1; i <= n; ++i) {
    cout << ans[i]  << " ";
  } 
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
