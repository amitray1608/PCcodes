//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const ll siz = 1e6 + 5;
const ll MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

ll root(ll x) {
  if(parent[x] == x)
    return x;
  return parent[x] = root(parent[x]);
}
 
void unions(ll u, ll v) {
  u = root(u);
  v = root(v);
  if(u != v) {
    if(ranks[v] > ranks[u])
      swap(u, v);
    parent[v] = u;
    if(ranks[u] == ranks[v])
      ranks[u]++;
  }
}
 
struct Edge {
  ll u, v, w;
  bool operator<(Edge const &o) {
    return w < o.w;
  }
};
 
vector<Edge>e;
int main() {
 
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  ll n, m;
  cin >> n >> m;
  parent.resize(n);
  ranks.resize(n);
  e.resize(m);
  vector<Edge>res;
  for(ll i = 0; i < n; i++) {
    parent[i] = i;
    ranks[i] = 0;
  }
  for(ll i = 0; i < m; i++) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--, v--; 
    e[i].u =  u;
    e[i].v = v;
    e[i].w = w;
  }
  sort(e.begin(), e.end());
  ll cost = 0;
  for(Edge ee : e) {
    if(root(ee.u) != root(ee.v)) {
      cost += ee.w;
      res.push_back(ee);
      unions(ee.u, ee.v);
    }
  }
    set<ll>ss;
    for(ll i : parent){
      ll x = root(i);
        ss.insert(x);
        // cout << i << ' ';
    }
    // cout << endl;
    if(ss.size() != 1)
        cout << "IMPOSSIBLE";
    else
      cout << cost << endl;
  return 0;
}
/*
4 4
1 2 5
2 4 6
3 4 5
2 3 5
*/