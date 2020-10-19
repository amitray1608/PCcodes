#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const ll MOD = 1e9 + 7;

struct DSU {
  vector<ll> data;
  DSU(ll n) {
    data.assign(n, -1);
  }
  bool unite(ll x, ll y) {
    x = root(x); 
    y = root(y);
    if(x != y) {
      if (data[y] < data[x]) 
        swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool issame(ll x, ll y) {
    return root(x) == root(y);
  }
  ll root(ll x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  ll size(ll x) {
    return -data[root(x)]; 
  }
};


void solve(){
  ll n, m;
  cin >> n >> m;
  DSU d(n);
  for(ll i = 0; i < m; i++) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    d.unite(u, v);
  }
  ll eroot = d.root(n - 1);
  ll total = (n * (n - 1))/ 2 - m;
  ll sroot = d.root(0);
  ll esize = d.size(eroot);
  ll ans = (total -  ((n - esize) * esize));
 // deb(ans);
  cout << ((ans&1) ? "First" : "Second") << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ll t = 1, tt = 0;
  cin >> t;
  while(t--){
  //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
}//Hajimemashite
