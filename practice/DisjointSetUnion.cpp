#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef double dd;
const int MOD = 1e9 + 7;

template<typename T>
class dsu {
  public:
    vector<T>p;
    vector<T>rank;
    T n;

    dsu(T _n) : n(_n) {
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
    bool isame(T u, T v) {
      return (root(u) == root(v));
    }
};

void solve(){
  int n, m;
  cin >> n >> m;
  dsu<int> d(n);
  while(m--) {
    string s;
    cin >> s;
    int u, v;
    cin >> u >> v;
    u--, v--;
    if(s == "union")
      d.unite(u, v);
    else
      cout << (d.isame(u, v) ? "YES" : "NO") << endl;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
