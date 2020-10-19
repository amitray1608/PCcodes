//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

template<typename T>
class DSU { 
  public:
  T n;
  vector<T>p, w;
  DSU(T _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    w.resize(n);
    fill(w.begin(), w.end(), 1);
  }

  T root(T x) {
    return (x == p[x] ? x : root(p[x]));
  }
  
  bool isconnected(T u, T v) {
    return (root(u) == root(v));
  }

  void unite(T u, T v) {
    u = root(u);
    v = root(v);
    if(u != v) {
      if(w[u] < w[v])
        swap(u, v);
      p[v] = u;
      w[u] += w[v];
    }
  }
};

void solve(){
  int n, q;
  cin >> n >> q;
  DSU<int> d(n);
  for(int i = 0; i < q; i++) {
    int t, u, v;
    cin >> t >> u >> v;
    u--, v--;
    if(t == 1) {
      d.unite(u, v);
    } else {
      if(d.isconnected(u, v)) 
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  