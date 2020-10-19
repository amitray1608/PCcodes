//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
const int INF = 1e9;


struct Edge {
  int u, v, w;
  bool operator<(Edge const & o) {
    return w < o.w;
  }
};

vector<Edge>e;

template<typename T>
class dsu {
  public:
    T n;
    vector<T>p, w;
    dsu(T _n) : n(_n) {
      p.resize(n);
      w.resize(n);
      iota(p.begin(), p.end(), 0);
      fill(w.begin(), w.end(), INF);
    }

    inline bool same(T x, T y) {
      return root(x) == root(y);
    }

    inline T root(T x) {
      return (x == p[x] ? x : (p[x] = root(p[x])));
    }
    inline void unite(T x, T y) {
      x = root(x);
      y = root(y);
      if(x != y) {
        if(w[x] < w[y]) {
          p[y] = x;
          w[y] = w[x];
        } else {
          p[x] = y;
          w[x] = w[y];
        }
      }
    }
};


void solve(){
  int n, m;
  cin >> n >> m;
  dsu<int> d(n);
  for(int i = 0; i < m; i++){
    int x, y;
    cin >> x >> y;
    x--, y--;
    e.push_back({x, y, 0});
  }

  for(int i = 0; i < n; i++) {
    cin >> d.w[i];
  }
  int cost = 0;
  for(Edge ee : e) {
    d.unite(ee.u, ee.v);
  }
  e.clear();
  // for(int &i : d.p){
  //   cout << i << ' ';
  // }
  // cout << endl;
  vector<int>v;
  for(int i = 0; i < n; i++) {
    if(d.p[i] == i)
      v.push_back(i);
  }
  for(int i : v) {
    for(int j : v) {
      if(j != i and d.w[i] != -1 and d.w[j] != -1){
        e.push_back({i, j, d.w[i]+d.w[j]});
      }
    }
  }
  sort(e.begin(), e.end());
  // for(Edge ee : e) {
  //   cout << ee.u << ' ' << ee.v << ' ' << ee.w << endl;
  // }
  for(Edge ee : e) {
    if(!d.same(ee.u, ee.v)) {
      cost += ee.w;
      d.unite(ee.u, ee.v);
    }
  }
  int count = 0;
  for(int i = 0; i < n; i++) {
    if(d.p[i] == i)
      count++;
  }
  if(count > 1)
    cout << -1 << endl;
  else
    cout << cost << endl;
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