//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const ll siz = 1e6 + 5;
const ll MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

ll n;
vector<vector<ll> >adj, adj2;
vector<ll> a, b, p, ans;
vector<ll> vis;
unordered_map<ll, ll> daymap;

template<typename T>
class DSU {
public:
  T n;
  vector<T> p;
  DSU(T _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }

  T root(T x) {
    return (p[x] == x ? x : p[x] = root(p[x]));
  }

  void unite(T x, T y) {
    y = root(y);
    p[y] = x;
    adj2[x].push_back(y);
    adj2[y].push_back(x);
  }

  bool same(T x, T y) {
    return root(x) == root(y);
  }

};

vector<ll> st, day; 

void dfs(ll s) {
  vis[s] = true;
  // deb(s);
  day.push_back(daymap[s]);
  if(st.size() == 0)
    st.push_back(a[s]);
  else { 
    // cout << st.back() << endl;
    st.push_back(a[s]+ st.back());
  }
  auto pos = lower_bound(st.begin(), st.end(), b[s]);
  // cout << pos-st.begin() << endl;
  if(pos != st.end())
    ans[s] = day[pos - st.begin()];
  for(auto i : adj2[s]) {
    if(!vis[i])
      dfs(i);
  }
  st.pop_back();
  day.pop_back();

}

void solve() {
  cin >> n;
  adj.resize(n);
  a.resize(n); 
  b.resize(n); 
  p.resize(n); 
  vis.resize(n, 0);
  ans.resize(n, -1); 
  for(ll i = 0; i < n-1; i++) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  ll dda = 0;
  for(ll &i : p) cin >> i, i--, daymap[i] = ++dda;
  for(ll &i : a) cin >> i;
  for(ll &i : b) cin >> i;

  DSU<ll> d(n);
  adj2.resize(n);

  for(ll i = n-1; i >= 0; i--) {
    ll s = p[i];
    for(ll j : adj[s]) {
      if(!vis[j]) continue;
      d.unite(s, j);
    }
    vis[s] = true;
  }
  ans.resize(n, -1);
  vis.clear();
  vis.resize(n, false);
  dfs(p[0]);


  for(ll &i : ans)
    cout << i << ' ';
  cout << endl;
  p.clear();
  b.clear();
  a.clear();
  ans.clear();
  st.clear();
  day.clear();
  vis.clear();
  for(ll i = 0; i < n; i++)
    adj[i].clear(), adj2[i].clear();
}

int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  ll t = 1;
  cin >> t;
  for(ll tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  

/*
2
3
1 2
2 3
1 2 3
1 2 3
1 3 6
3
1 2
1 3
1 2 3
5 6 3
4 10 12

1
8
1 2
1 3
1 4
3 5
5 8
6 5
6 7
1 6 8 2 7 4 3 5
1 2 3 4 5 6 7 8
1 2 3 4 5 6 6 7
sol 1 4 2 6 2 2 2 2

1
6
4 1
1 5
1 3
3 2
3 6
6 1 4 3 2 5
10 10 10 10 10 10
10 12 14 16 18 20
sol 1 2 2 2 2 -1

1
7
1 4
1 5
1 2
2 3
3 6
3 7
6 4 1 3 7 2 5
3 5 2 5 4 6 2
10 5 6 8 11 7 12
sol 2 1 1 2 2 -1 3
*/