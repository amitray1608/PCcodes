#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
#define int long long
typedef long double ld;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

template <typename T>
class fenwick {
public:
  vector<T> fenw;
  int n;

  fenwick(int _n) : n(_n) {
    fenw.resize(n, 0);
  }

  void modify(int x, T v) {
    x++;
    while(x < n) {
      fenw[x] += v;
      x += x & -x;
    }
  }

  T get(int x) {
    T v = 0;
    x++;
    while (x) {
      v += fenw[x];
      x -= x & -x;
    }
    return v;
  }
};

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  int row[n], col[m];
  fill(row, row + n, m);
  fill(col, col + m, n);
  while(q--){
    int x, y;
    cin >> x >> y;
    x--, y--;
    row[x] = min(row[x], y);
    col[y] = min(col[y], x);
  }
  bool ok = 0;
  int ans = 0;
  for(int i = 0; i < n; i++){
    if(ok){
      row[i] = 0;
      continue;
    }
    if(!row[i]){
      ok = 1;
      break;
    }
    ans += row[i];
  }
  fenwick<int> f(N);
  vector <int> mat[m + 1];
  for(int i = 0; i < n; i++){
    mat[row[i]].push_back(i);
  }
  for(int i = 0; i < m; i++){
    ans += f.get(col[i] - 1);
    for(auto j : mat[i])
      f.modify(j, 1);
  }
  cout << ans;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
    //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite
