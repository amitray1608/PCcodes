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
  vector<T> p;
  vector<array<T, 3>> w;
  T n;
  dsu(T _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    w.resize(n);
    for(int i = 0; i < n; i++)
      w[i][0] = 1, w[i][1] = i, w[i][2] = i;
  }
  bool unite(T x, T y) {
    x = root(x); y = root(y);
    if(x != y) {
      if (w[y][0] < w[x][0])
        swap(x, y);
      w[x][0] += w[y][0]; 
      p[y] = x;
      w[x][1] = min(w[x][1], w[y][1]);
      w[x][2] = max(w[x][2], w[y][2]);
    }
    return x != y;
  }
  T root(T x) {
    return p[x] == x ? x : p[x] = root(p[x]);
  }
  auto get(T x) {
    return w[root(x)];
  }
};


void solve(){
  int n, m;
  cin >> n >> m;
  dsu<int> d(n);
  while(m--) {
    string s;
    cin >> s;
    if(s == "union") {
      int u, v;
      cin >> u >> v;
      u--, v--;
      bool x =  d.unite(u, v);
    } else {
      int x;
      cin >> x; x--;
      auto ans = d.get(x);
      cout << ans[1]+1 << ' ' << ans[2]+1 << ' ' << ans[0] << endl;
    }
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
