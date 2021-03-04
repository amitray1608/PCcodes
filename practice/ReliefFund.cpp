
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

template<typename T>
class dsu {
  public:
    vector<T>p;
    vector<T>rank, weight; 
    T n;
    dsu(T _n) : n(_n) {
      p.resize(n);
      rank.resize(n, 0);
      weight.resize(n, 1);
      iota(p.begin(), p.end(), 0);
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
      if(x != y) {
        p[x] = y;
        weight[y] += weight[x];
        weight[x] = 0;
        rank[y] += rank[x];
        rank[x] = 0;
      }
    }
    bool isame(T u, T v) {
      return (root(u) == root(v));
    }
};


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  dsu<ll> d(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    d.rank[i] = a[i];
  }
  int p;
  cin >> p;
  while (p--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    d.unite(u, v);
  }
  ll maxi = 0, size = INT_MAX, pos = 0;
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (d.p[i] != i) continue;
    if (d.rank[i] == maxi) {
      if (d.weight[i] < size) size = d.weight[i], pos = i;
    } else if (d.rank[i] > maxi) {
      maxi = d.rank[i];
      size = d.weight[i];
      pos = i;
    }
  }
  for (int i = 0; i < n; i++) {
    if (d.isame(i, pos)) ans.push_back(i + 1);
//    cout << d.weight[i] << ' ';
  }
//  cout << endl;
  for (int i : ans) cout << i << ' ';
  cout << '\n';
  return 0;
} //Hajimemashite
