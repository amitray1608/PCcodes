#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef double dd;
const ll MOD = 1e9 + 7;

template<typename T>
string to_string(vector<T> v) {
  string res;
  for(auto &i : v)
    res += char('0'+i), res += ", ";
  res.pop_back(), res.pop_back();
  return res;
}
 
template<class A> void vbug(A x) {
  cout << '[' << to_string(x) << ']' << endl;
}


vector<ll>is_prime, prime;
void seive(ll n) {
  is_prime.assign(n+1, true);
  is_prime[0] = is_prime[1] = false;
  for (ll i = 2; i <= n / i; i++) {
    if (is_prime[i]) {
      for (ll j = i * i; j <= n; j += i)
          is_prime[j] = false;
    }
  }
  for(ll i = 2; i <= n; i++)
    if(is_prime[i])
      prime.push_back(i);
}

class CentroidDecomposition {
 public:
  vector<set<ll>>adj;
  vector<ll>d, sub, par;
  ll ans, N;
  CentroidDecomposition(vector<set<ll>> &a) : adj(a) {
    ll n = adj.size();
    N = n;
    d.assign(n, 0);
    par.assign(n, 0);
    sub.assign(n, 0);
    ans = 0;
    build(0, -1);
  }
  void build(ll u, ll p) {
    dfs(u, p);
    ll c = dfs(u, p, sub[u]);
    dfs(c, 0, 0, 1);
    ll count = 0;
    for(auto i : adj[c]) {
      dfs(i, c, 1, -1);
      count += get(i, c, 1);
      dfs(i, c, 1, 1);
    }
    ans += count/2;
    for(ll i = 0; i < N and d[i]; i++) d[i] = 0;
    for(auto i : adj[c]) {
      adj[i].erase(c);
      build(i, c);
    }
  }
  ll dfs(ll u, ll p) {
    sub[u] = 1;
    for(auto i : adj[u]) 
      if(i != p) sub[u] += dfs(i, u);
    return sub[u];
  }
  ll dfs(ll u, ll p, ll n) {
    for(auto i : adj[u])
      if(i != p and sub[i] > n/2)
        return dfs(i, u, n);
    return u;
  }
  void dfs(ll u, ll p, ll lv, ll val) {
    d[lv] += val;
    for(auto i : adj[u]) {
      if(i != p)
        dfs(i, u, lv+1, val); 
    }
  }
  ll get(ll u, ll p, ll l) {
    ll res = 0;
    for(auto i : prime) {
      if(i - l < 0) continue;
      if(!d[i - l]) break;
      res += (l == i) ? (d[i - l] << 1) : d[i - l];
    }
    for(auto i : adj[u])
      if(i != p)
        res += get(i, u, l+1);
    return res;
  }
};

void solve(){
  ll n;
  cin >> n;
  seive(n+1);
  //vbug(prime);
  vector<set<ll>>adj(n+1);
  for(ll i = 0; i < n - 1; i++) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].insert(v);
    adj[v].insert(u);
  }
  CentroidDecomposition d(adj);
  //vbug(d.d);
  double total = (n * (n - 1) >> 1);
  double ans = (double)d.ans / total;
  cout << ans << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 // freopen("output.txt", "w", stdout);
  cout << fixed << setprecision(6);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
  //cout << "Case #" << ++t << ": ";
    solve();
  }
  return 0;
}

