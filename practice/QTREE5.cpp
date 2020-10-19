#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef double dd;
const int MOD = 1e9 + 7;

const int inf = 1e8;
vector<set<int>>adj;
vector<int>status;
vector<set<pair<int, int>>>ans;

template<typename T>
string to_string(vector<T> v) {
  string res;
  for(auto &i : v)
    res += char('0'+i), res += ", ";
  res.pop_back(), res.pop_back();
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
  
  void dfs(T v, T p, T lev) {
    tin[v] = ++timer;
    dp[v][0] = p;
    level[v] = lev;
    for(int i = 1; i <= l; i++) 
      dp[v][i] = dp[dp[v][i-1]][i-1];
    for(auto u : adj[v])
      if(u != p)
        dfs(u, v, lev+1);
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

template<typename T>
class CentroidDecomposition { 
 public:
  vector<T>sub, par;
  vector<set<T>>adj;
  CentroidDecomposition(vector<set<T>> &a) : adj(a) {
    T n = adj.size();
    par.resize(n);
    sub.resize(n);
    par[0] = -1;
    build(0, -1);
  }

  void build(T u, T p) {
    T n = dfs(u, p);
    T c = dfs(u, p, n);
    par[c] = p;
    for(auto i : adj[c]) {
      adj[i].erase(c);
      build(i, c);
    }
  }
  
  T dfs(T u, T p) {
    sub[u] = 1;
    for(auto i : adj[u]) 
      if(i != p) sub[u] += dfs(i, u);
    return sub[u];
  }

  T dfs(T u, T p, T n) {
    for(auto i : adj[u])
      if(i != p and sub[i] > n/2)
        return dfs(i, u, n);
    return u;
  }
};


void solve(){
  int n;
  cin >> n;
  adj.resize(n);
  ans.resize(n);
  status.resize(n, 0);
  for(int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].insert(v);
    adj[v].insert(u);
  }
  
  LCA<int> l(n, adj);
  CentroidDecomposition<int> cd(adj);
  for(int i = 0; i < n; i++) {
    ans[i].insert({inf, -1});
  }
  auto update1 = [&](int node) {
    for(int i = node; i != -1; i = cd.par[i]) {
      ans[i].insert({l.dist(node, i), node});
    }
  };

  auto update2 = [&](int node) {
    for(int i = node; i != -1; i = cd.par[i]) {
      ans[i].erase({l.dist(i, node), node});
    }
  };

  auto query = [&](int x) {
    int anss = inf;
    for(int i = x; i != -1; i = cd.par[i]) {
      auto c = *ans[i].begin();
      int cc = c.first + l.dist(i, x);
      anss = min(anss, cc);
    }
    if(anss >= inf) return -1;
    return anss;
  };

  int q;
  cin >> q;
  while(q--) {
    int type;
    cin >> type;
    if(!type) {
      int x;
      cin >> x; x--;
      (status[x]) ? update2(x) : update1(x);
      status[x] ^= 1;
    } else {
      int x;
      cin >> x; x--;
      int d = query(x);
      cout << d << endl; 
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
    //cout << "Case #" << ++t << ": ";
    solve();
  }
  return 0;
}
