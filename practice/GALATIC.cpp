//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

int n, m, ncc;
vector<int> val;
// template <typename T>
class DSU {
public:
  int n;
  vector<int>p;
  vector<int>w;
  DSU (int _n) : n(_n) {
    p.resize(n, -1);
    w.resize(n);
    fill(w.begin(), w.end(), 1);
  }
  int root(int x) {
    int tx = x;
    while(p[tx] > -1)
      tx = p[tx];
    while(x != tx) {
      int rx = p[x];
      p[x] = tx;
      x = rx;
    }
    return tx;
  }

  void unite(int u, int v) {
    int x = root(u);
    int y = root(v);
    if(x == y) return;
    ncc--;
      if(w[y] < w[x]) 
        swap(x, y);
      p[x] = y;
      w[y] += w[x];
  }

};

void solve() {
  cin >> n >> m;
  DSU d(n);
  ncc = n;
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    d.unite(u, v);
  }
  if(ncc == 1) {
    cout << 0 << endl;
    return ;
  }
  val = vector<int> (n, -1);
  for(int i = 0; i < n; i++) {
    int c;
    cin >> c;
    if(c < 0) continue;
    int j = d.root(i);
    if(val[j] < 0 or c < val[j])
      val[j] = c;
  }

  int cost = 0, mini = INT_MAX;
  for(int i = 0; i < n; i++) {
    if(d.p[i] > -1)
      continue;
    if(val[i] < 0) {
      cout << -1 << endl;
      return ;
    }
    cost += val[i];
    if(val[i] < mini)
      mini = val[i];
  }
  cout << cost + (ncc-2)*mini << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  // cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  