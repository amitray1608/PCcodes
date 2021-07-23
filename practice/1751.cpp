
#include<bits/stdc++.h>

using namespace std;

template <typename T>
class dsu {
public:
  vector<T> p;
  vector<T> rank;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    rank.resize(n);
    iota(p.begin(), p.end(), 0);
    fill(rank.begin(), rank.end() , 1);
  }

  inline T get(T x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline void unite(T x, T y) {
    x = get(x);
    y = get(y);
    if(x != y) {
      p[y] = x;
      rank[x] += rank[y];
      rank[y] = 0;
    }
  }
  inline T getrank(int x) {
    return rank[x];
  }
};


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n;
  cin >> n;
  dsu<int> d(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    x--;
    d.unite(i, x);
  }
  for (int i = 0; i < n; i++) {
    int x = d.get(i);
    cout << d.getrank(x) << ' ';
  } cout << '\n';
  return 0;
} //Hajimemashite

