#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef double dd;
const int MOD = 1e9 + 7;
const int inf = 1e9;

vector<set<int>>adj;
vector<int>dis;

template<typename T>
string to_string(vector<T> v) {
  string res;
  for(auto &i : v)
    res += char('0'+i), res += ' ';
  return res;
}
 
template<class A> void vbug(A x) {
  cout << '[' << to_string(x) << ']' << endl;
}


template<typename T>
class LCA {
 public:
  T n, l;
  vector<set<T>> adj;
  T timer;
  vector<T> tin, tout, level;
  vector<vector<T>> dp;

  LCA(T _n, vector<set<T>>&a) : n(_n), adj(a) {
    tin.resize(n);
    tout.resize(n);
    level.resize(n);
    timer = 0;
    l = ceil(log2(n));
    dp.assign(n, vector<T>(l + 1));
    dfs(0, 0, 0);
  }
  
  void dfs(T v, T p, int lv) {
    tin[v] = ++timer;
    dp[v][0] = p;
    level[v] = lv;
    for(int i = 1; i <= l; i++) 
      dp[v][i] = dp[dp[v][i-1]][i-1];
    for(auto u : adj[v])
      if(u != p)
        dfs(u, v, lv+1);
    tout[v] = ++timer;
  }

  bool is_ancestor(T u, T v) {
    return tin[u] <= tin[v] and tout[u] >= tout[v];
  }

  T lca(T u, T v) {
    if(is_ancestor(u, v))
      return u;
    if(is_ancestor(v, u))
      return v;
    for(T i = l; i >= 0; i--)
      if(!is_ancestor(dp[u][i], v))
          u = dp[u][i];
    return dp[u][0];
  }
  T dist(T u, T v) { 
    return (level[u] + level[v] - (level[lca(u,v)] << 1));
  }
};


template<typename T>
class CentroidDecomposition {
 public:
  int n;
  vector<set<T>>adj;
  vector<T>par;
  vector<T>sub;

  CentroidDecomposition(T _n, vector<set<T>> &a) : n(_n),
    adj(a){
    par.resize(n);
    sub.resize(n);
    build(0, 0);
  }

  void build(int u, int p) {
    int n = dfs(u, p);
    int c = dfs(u, p, n);
    par[c] = p;
    for(auto v : adj[c]) {
      adj[v].erase(c);
      build(v, c);
    }
  }
  
  int dfs(int u, int p) {
    sub[u] = 1;
    for(auto v : adj[u])
      if(v!= p) sub[u] += dfs(v, u);
    return sub[u];
  }

  int dfs(int u, int p, int n) {
    for(auto v : adj[u])
      if(v != p and sub[v] > n/2) 
        return dfs(v, u, n);
    return u;
  }
};


void solve(){
  int n, q;
  cin >> n >> q;
  adj.resize(n);
  dis.resize(n, inf);
  for(int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].insert(v);
    adj[v].insert(u);
  }
  
  LCA <int> l(n, adj);
  //vbug(l.level);
  CentroidDecomposition <int> cd(n, adj);
  //vbug(cd.par); 

  dis[0] = 0;
  for(int i = 1; i < n; i++)
    dis[i] = l.dist(i, 0);
  //vbug(dis);
  //vbug(cd.par);
  //return;
  auto query = [&](int x) {
    int ans = dis[x];
    for(int i = x; i; i = cd.par[i])
      ans = min(ans, l.dist(i, x) + dis[i]);
    return ans;
  };
  
  auto update = [&](int x) {
    for(int i = x; i; i = cd.par[i])
      dis[i] = min(dis[i], l.dist(i, x));
  };
 // vbug(dis);
  while(q--) {
    int type;
    cin >> type;
    if(type == 1) {
      int x;
      cin >> x; x--;
    //deb(x);
     update(x);
    } else {
      int x;
      cin >> x; x--;
    //deb(x);
      cout << query(x) << endl;
    }
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

