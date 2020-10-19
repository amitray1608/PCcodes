#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;

template<typename T>
struct DSU {
  vector<T> p, add, sub;
  DSU(T n) {
    p.assign(n, -1);
    add.assign(n, 0);
    sub.assign(n, 0);
  }
  bool unite(T x, T y) {
    x = root(x); y = root(y);
    if(x != y) {
      if (p[y] < p[x])
        swap(x, y);
      p[x] += p[y];
      sub[x] = add[y];
      p[y] = x;
    }
    return x != y;
  }
  inline T root(T x) {
    if(x == p[x]) return x;
    add[x] = getsum(x);
    p[x] = root(p[x]);
    sub[x] = add[p[x]];
    return (p[x] = root(p[x]));
  }
  bool issame(T x, T y) {
    return root(x) == root(y);
  }

  inline void update(T x, T val) {
      add[root(x)] += val;
  }
  inline T getsum(T x) {
    if(p[x] == x) return add[x];
    return add[x] - sub[x] + getsum(p[x]);
  } 

  inline T size(T x) {
    return -p[root(x)]; 
  }
};


void solve(){
  int n, m;
  cin >> n >> m;
  DSU<int> d(n);
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
