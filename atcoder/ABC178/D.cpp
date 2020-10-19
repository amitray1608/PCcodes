//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

class DSU {
public:
  int n;
  vector<int> p, ww;
  DSU(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    ww.resize(n);
    fill(ww.begin(), ww.end(), 1);
  }
  int root(int x) {
    return (p[x] == x ?  x : p[x] = root(p[x]));
  }
  bool issame(int x, int y) {
    return root(x) == root(y);
  }
  void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if(x != y) {
      if(ww[x] > ww[y])
        swap(x, y);
      p[y] = x;
      ww[x] += ww[y];
      ww[y] = 0;
    }
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  DSU d(n);
  for(int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    d.unite(x, y);
  }
  int maxi = 0;
  for(int i = 0; i < n; i++) {
    maxi = max(maxi, d.ww[i]);
  }
  cout << maxi << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  //cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  