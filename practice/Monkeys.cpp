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
    vector<T>rank, moment;
    T n;
    dsu(T _n) : n(_n) {
      p.resize(n);
      rank.resize(n);
      moment.resize(n, -1);
      iota(p.begin(), p.end(), 0);
      fill(rank.begin(), rank.end(), 1);
      rank[0] = -10;
    }
    inline T root(T x, T time) {

      return (x == p[x] ? x : (p[x] = root(p[x])));
    }
    
    inline bool same(int u, int v) {
      return(root(u) == root(v));
    }

    inline void unite(T u, T v, T connect) {
      int x = root(u);
      int y = root(v);
      if(x != y) {
        if(rank[y] < rank[x]) 
          swap(x, y);
        p[x] = y;
        if(x == 0 and moment[v] == -1) {
          moment[v] = connect;
        } else if(y == 0 and moment[u] == -1){
          moment[u] = connect;
        }
        if(rank[x] == rank[y])
          rank[y]++;
      }
    }
};

void solve(){
  int n, m;
  cin >> n >> m;
  dsu<int> d(n);
  vector<array<int, 3>> adj(n);
  for(int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[i][0] = u, adj[i][1] = v;
  }
  vector<array<int, 2>> q(m);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    v = adj[u][v];
    d.unite(u, v, i+1);
  }
  for(int i = 0; i < n; i++) 
    cout << d.moment[i] << ' ';
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
