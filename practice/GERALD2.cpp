#include <bits/stdc++.h>
using namespace std;
#define MaxN 200001



int timer, in[MaxN], out[MaxN], dep[MaxN], blift[MaxN][18];
struct LCA {
  void dfs(int a, int p, vector<int> tree[]) {
    in[a] = ++timer;
    dep[a] = dep[p]+1;
    blift[a][0] = p;
    for (int i = 1; i < 18; ++i) blift[a][i] = blift[blift[a][i-1]][i-1];
    for (int& c:tree[a]) if (c!=p) dfs(c,a,tree);
    out[a] = ++timer;
  }
  bool isanc(int a, int b) { return in[a] <= in[b] && out[a] >= out[b]; }
  int lca(int a, int b) {
    if (isanc(a,b)) return a;
    if (isanc(b,a)) return b;
    for (int i = 17; ~i; --i) if(!isanc(blift[a][i],b)) a = blift[a][i];
    return blift[a][0];
  }
  int dist(int a, int b) { return dep[a] + dep[b] - (dep[lca(a,b)]<<1); }
  void operator() (vector<int> tree[]) {
    timer = 0, dep[0] = -1;
    dfs(0,0,tree);
  }
  int operator() (int a, int b) {
    return dist(a,b);
  }
  LCA(){}
};

int par[MaxN], dead[MaxN], sz[MaxN];
struct Centroid {
  int subtree(int a, int p, vector<int> tree[]) {
    int ret = sz[a] = 1;
    for (int& c:tree[a]) if(c!=p&&!dead[c]) ret += subtree(c,a,tree);
    return sz[a] = ret;
  }
  int OneCentroid(int a, int p, int size, vector<int> tree[]) {
    for (int& c:tree[a]) if(c!=p&&!dead[c]&&sz[c]>(size>>1)) return OneCentroid(c,a,size,tree); 
    return a;
  }
  void decompose(int a, int p, vector<int> tree[]) {
    int cent = OneCentroid(a,-1,subtree(a,-1,tree),tree);
    dead[cent] = 1, par[cent] = p;
    for (int& c:tree[cent]) if (!dead[c]) decompose(c,cent,tree);
  }
  Centroid() {}
  void operator() (vector<int> tree[]) {
    memset(dead,0,sizeof dead);
    decompose(0,-1,tree);
  }
  int operator[] (int id) { return par[id]; }
};

array<int,3> operator+ (const array<int,3> a, const int d) {
  return (a[0] == -1) ? a : array<int,3>({a[0]+d,a[1],a[2]});
}

class comp {
public:
  bool operator() (const array<int,3> a, const array<int,3> b) const {
    if (a[0] == b[0]) {
      if (a[1] == b[1]) return a[2] > b[2];
      return a[1] > b[1];
    } return a[0] > b[0];
  }
};

int iswhite[MaxN];
struct solution {
  LCA dist;
  Centroid par;
  vector<set<array<int,3>, comp>> setd;
  vector<map<int,array<int,3>>> mpi;
  void addwhite(int i) {
    array<int,3> x = mpi[i][i];
    setd[i].erase(x);
    x = {0,i,i};
    setd[i].insert(mpi[i][i] = x);
    x = *setd[i].begin();
    x[2] = i;
    for (int u = i; par[u] != -1; u = par[u]) {
      array<int,3> tx = mpi[par[u]][u];
      setd[par[u]].erase(tx);
      setd[par[u]].insert(mpi[par[u]][u] = x + dist(u,par[u]));
      x = *setd[par[u]].begin();
      x[2] = par[u];
    }
  }
  void remwhite(int i) {
    array<int,3> x = mpi[i][i];
    setd[i].erase(x);
    x = {-1,i,i};
    setd[i].insert(mpi[i][i] = x);
    x = *setd[i].begin();
    x[2] = i;
    for (int u = i; par[u] != -1; u = par[u]) {
      array<int,3> tx = mpi[par[u]][u];
      setd[par[u]].erase(tx);
      setd[par[u]].insert(mpi[par[u]][u] = x + dist(u,par[u]));
      x = *setd[par[u]].begin();
      x[2] = par[u];
    }
  }
  void __init__(int n) {
    for (int i = 0; i < n; ++i) {
      setd[i].insert(mpi[i][i] = {-1,i,i});
      if (par[i] != -1) 
        setd[par[i]].insert(mpi[par[i]][i] = {-1,i,i});
    }
    for (int i = 0; i < n; ++i) {
      addwhite(i);
      iswhite[i] = 1;
    }
  }
  solution(vector<int> adj[], int N) {
    par(adj);
    dist(adj);
    cout << "okk" << endl;
    setd.resize(N);
    cout << "okk" << endl;
    exit(0);
    mpi.resize(N);
    __init__(N);
      cout << "okk" << endl;
    exit(0);
  }
  int operator[] (int i) {
    int flag = iswhite[i];
    if (!iswhite[i]) addwhite(i), iswhite[i] = 1;
    array<int,3> ret = *setd[i].begin();
    for (int u = i; par[u] != -1; u = par[u]) {
      auto tx = setd[par[u]].begin();
      if ((*tx)[2] == u) advance(tx,1);
      array<int,3> x = *tx + dist(i,par[u]);
      ret = (ret < x) ? x : ret;
    }
    if (flag) remwhite(i), iswhite[i] = 0;
    return ret[1] + 1;
  }
};

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int Tests;
  cin >> Tests;
  for (int Test = 1; Test <= Tests; ++Test) {
    int N, Q;
    cin >> N >> Q;
    vector<int> tree[N];
    for (int v = 1; v < N; ++v) {
      int u;
      cin >> u;
      --u;
      tree[u].push_back(v);
      tree[v].push_back(u);
    }
    solution ans(tree, N);
    cout << "ok" << endl;
    return 0;
    while (Q--) {
      int q;
      cin >> q;
      cout << ans[--q] << '\n';
    }
  }
  return 0;
}

