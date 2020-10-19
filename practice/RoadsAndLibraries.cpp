#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef double dd;
const int MOD = 1e9 + 7;

template<typename T>
class DSU {
 public:
  T n;
  vector<T> p, w;
  DSU(T _n) : n(_n) {
    p.resize(n);
    w.resize(n);
    fill(w.begin(), w.end(), 1);
    iota(p.begin(), p.end(), 0);
  }

  T root(T x) {
    return (p[x] == x ? x : p[x] = root(p[x]));
  }

  void unite(T u, T v) {
    u = root(u);
    v = root(v);
    if(u != v) {
      if(w[v] < w[u])
        swap(v, u);
      p[v] = u;
      w[u] += w[v];
      w[v] = 0;
    }
  }

  T same(T u, T v) {
    return root(u) == root(v);
  }

  T operator() (T x) {
    return p[x];
  }

  T operator[] (T x) {
    return w[x];
  }
};

void solve(){
  int n, m, l, r;
  cin >> n >> m >> l >> r;
  DSU <int>d(n);
  int mini = n*l;
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    d.unite(u, v);
  }
  int cost = 0;
  for(int i = 0; i < n; i++) {
    if(d(i) == i) {
      cost += (d[i] - 1) * r + l;
    }
  }
  cout << min(mini, cost) << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
  //cout << "Case #" << ++t << ": ";
    solve();
  }
  return 0;
}
