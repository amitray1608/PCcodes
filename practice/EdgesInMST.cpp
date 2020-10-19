#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;

const int inf = 1e9;
vector<int> dis, parent;


struct Edge {
  int u, v, w, id;
  bool operator<(const Edge &a) {
    return w < a.w;
  }
};

vector<Edge> e;

template<typename T>
class dsu {
  public:
    vector<T>p;
    vector<T>rank;
    ll n;

    dsu(ll _n) : n(_n) {
      p.resize(n);
      rank.resize(n);
      iota(p.begin(), p.end(), 0);
      fill(rank.begin(), rank.end(), 1);
    }
    inline T root(T x) {
      return (x == p[x] ? x : (p[x] = root(p[x])));
    }
    
    inline bool same(int u, int v) {
        return(root(u) == root(v));
    }

    inline void unite(T x, T y) {
      x = root(x);
      y = root(y);
      if(x != y) {
        if(rank[y] < rank[x]) 
          swap(x, y);
        p[x] = y;
        if(rank[x] == rank[y])
          rank[y]++;
      }
    }
};

void solve(){
  int n, m;
  cin >> n >> m;
  dsu<int> d(n);
  e.resize(n);
  parent.resize(n);
  iota(parent.begin(), parent.ent(), 0);
  dis.resize(n, inf);
  vector<string> ans(m);
  for(int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    e.push_back({u, v, w, i});
  }
  
  sort(e.begin(), e.end());
  for(int i = 0; i < m; i++) {
    int u = e[i].u, v = e[i].v, w = w[i].w;
    if(!same(u, v)) {
      
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
