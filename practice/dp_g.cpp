#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

vector<vector<int>>adj;
vector<int>dp;
vector<bool> vis;

void dfs(int s) {
  vis[s] = true;
  for(auto i : adj[s]) {
    if(!vis[i])
      dfs(i);
    dp[s] = max(dp[i]+1, dp[s]);
  }
}

void solve(){
	int n, m;
  cin >> n >> m;
  adj.resize(n);
  dp.resize(n, 0);
  vis.assign(n, false);
  for(int i = 0; i < m; i++) {
    int u, v; 
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
  }
  for(int i = 0; i < n; i++) {
    if(!vis[i])
      dfs(i);
  }
  //for(int &i : dp)
  // cout << i << ' ' ;
  //cout << endl;
  cout << *max_element(dp.begin(), dp.end()) << endl;
}

int main(){
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1, tt = 0;
	//	cin >> t;
		while(t--){
			//tt++;
			//cout << "Case #" << t << ": ";
			solve();
		}
	return 0;
}
