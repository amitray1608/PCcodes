#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;

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

  inline bool unite(T x, T y) {
    T px = get(x);
    T py = get(y);
    if (px != py) {
      if(rank[px] == rank[py]){
        p[py] = px;
        rank[px]++;
      } else if(rank[px] < rank[py]){
        p[px] = py;
      } else {
        p[py] = px;
      }
      return true;
    }
    return false;
  }
};

void solve(){
  int n, m;
  cin >> n >> m;
  dsu<int> d(n);
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    d.unite(u, v);
  }
  int count = 0;
  for(int i = 0; i < n; i++)
    if(d.p[i] == i) count++;
  cout << count << endl;
}

int main(){
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
