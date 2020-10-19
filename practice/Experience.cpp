#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;

template<typename T>
class dsu {
  public:
    vector<T>p;
    vector<T>rank, add, sub;
    T n;

    dsu(T _n) : n(_n) {
      p.resize(n);
      rank.resize(n);
      add.resize(n, 0);
      sub.resize(n, 0);
      iota(p.begin(), p.end(), 0);
      fill(rank.begin(), rank.end(), 1);
    }

    inline T root(T x) {
      if(x == p[x]) return x;
      add[x] = getsum(x);
      p[x] = root(p[x]);
      sub[x] = add[p[x]];
      return (p[x] = root(p[x]));
    }
    
    inline bool same(int u, int v) {
      return(root(u) == root(v));
    }
    
    inline T getsum(T x) {
      if(p[x] == x) return add[x];
      return add[x] - sub[x] + getsum(p[x]);
    } 

    inline void unite(T x, T y) {
      x = root(x);
      y = root(y);
      if(x != y) {
        if(rank[y] < rank[x]) 
          swap(x, y);
        p[x] = y;
        sub[x] = add[y];
        if(rank[x] == rank[y])
          rank[y]++;
      }
    }

    inline void update(T x, T val) {
      x = root(x);
      add[x] += val;
    }
};

void solve(){
  int n, m;
  cin >> n >> m;
  dsu<int> d(n);
  while(m--) {
    string s;
    cin >> s;
    if(s == "join") {
      int u, v;
      cin >> u >> v;
      u--, v--;
      d.unite(u, v);
    } else if(s == "add") {
      int u, val;
      cin >> u >> val;
      u--;
      d.update(u, val);
    } else {
      int x;
      cin >> x;
      x--;
      cout << d.getsum(x) << endl;
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
}//Hajimemashite
