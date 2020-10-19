#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;


template<typename T>
class LCA {
 public:
  T n, l;
  vector<vector<T>> adj, diss;
  T timer;
  vector<T> tin, tout, level;
  vector<vector<T>> dp;

  LCA(T _n, vector<vector<T>>&a, vector<vector<T>> &dis) : n(_n), adj(a), diss(dis) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    level.resize(n);
    l = ceil(log2(n));
    dp.assign(n, vector<T>(l + 1));
    dfs(0, 0, 0);
  }
  
  void dfs(T v, T p, T d) {
    tin[v] = ++timer;
    dp[v][0] = p;
    level[v] = d;
    for(int i = 1; i <= l; i++) 
      dp[v][i] = dp[dp[v][i-1]][i-1];
    for(auto u : adj[v])
      if(u != p)
        dfs(u, v, d+diss[u][v]);
    tout[v] = ++timer;
  }

  bool is_ancestor(T u, T v) {
    return tin[u] <= tin[v] and tout[u] >= tout[v];
  }

  T lca(int u, int v) {
    if(is_ancestor(u, v))
      return u;
    if(is_ancestor(v, u))
      return v;
    for(int i = l; i >= 0; i--)
      if(!is_ancestor(dp[u][i], v))
          u = dp[u][i];
    return dp[u][0];
  }
  T dist(T u, T v) {
    return (level[u] + level[v] - (level[lca(u,v)] << 1));
  }
};

void solve(){
  int n;
  cin >> n;
  vector<vector<int>> adj(n), dis(n, vector<int> (n, 0));
  for(int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
    dis[u][v] = w;
    dis[v][u] = w;
  }
  LCA<int> l(n, adj, dis);
  for(auto i : l.level) cout << i << ' ';
  cout << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
  //cout << "Case #" << ++t << ": ";
    solve();
  }
  return 0;
}//Hajimemashite
