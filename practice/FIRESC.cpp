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
class dsu {
  public:
    vector<T>p;
    vector<T>w;
    ll n;

    dsu(ll _n) : n(_n) {
      p.resize(n);
      w.resize(n);
      iota(p.begin(), p.end(), 0);
      fill(w.begin(), w.end(), 1);
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
      if(x == y) return;
      if(w[y] > w[x])
        p[x] = p[y], w[y] += w[x];
      else
        p[y] = p[x], w[x] += w[y];
    }
};

void solve() {
  int n, m;
  cin >> n >> m;
  dsu<int> d(n);
  for(int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    d.unite(x, y);
  }
  set<int>st;
  ll ans = 1, count = 0;
  for(int i = 0; i < n; i++) {
    if(d.p[i] == i) {
      count++;
      ans = (ans*d.w[i])%MOD;
    }
  }

  cout << count  << ' ' << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  