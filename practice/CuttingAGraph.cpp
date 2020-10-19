#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;

struct Query {
  string s;
  int u, v;
};

template<typename T>
class dsu {
  public:
    vector<T>p;
    vector<T>rank;
    ll n;
    dsu(ll _n) : n(_n) {
      p.resize(n);
      rank.resize(n);
      iota(p.begin(), p.end(), 0);
      fill(rank.begin(), rank.end(), 1);
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
        if(rank[y] < rank[x]) 
          swap(x, y);
        p[x] = y;
        if(rank[x] == rank[y])
          rank[y]++;
      }
    }
};

void solve(){
  int n, m, q;
  cin >> n >> m >> q;
  dsu<int> d(n);
  string s;
  int u, v;
  for(int i = 0; i < m; i++) {
    cin >> u >> v;
  }
  vector<Query> qq(q);
  for(int i = 0; i < q; i++) {
    cin >> s;
    cin >> u >> v;
    u--, v--;
    qq[i].s = s, qq[i].u = u, qq[i].v = v;
  }
  vector<string>ans;
  for(int i = q-1; i >= 0; i--) {
    s = qq[i].s, u = qq[i].u, v = qq[i].v;
    if(s == "ask") {
      ans.push_back(("YES" : "NO");
    } else 
      d.unite(u, v);
  }
  for(int i = (int)ans.size()-1; i >= 0; i--)
    cout << ans[i] << endl;
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
