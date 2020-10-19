//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const ll siz = 1e6 + 5;
const ll MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

struct Edge {
  ll c, f, w;
};

bool operator<(const Edge& p, const Edge& o) {
  return p.f* ceil((dd)p.c/2.0) < ceil((dd)o.c/2.0)*o.f;
}

vector<Edge>e;

ll n, S;
vector<vector<pair<ll, pair<ll, ll>>>>adj;

ll dfs(ll s, ll p) {
  ll fre = 0;
  bool flag = true;
  for(auto i : adj[s]) if(i.first != p){
    ll c = dfs(i.first, s);
    e.push_back({i.second.first, c, i.second.second});
    flag = false;
    fre += c;
  }
  if(flag)
    return 1;
  else
    return fre;
}

void solve() {
  cin >> n >> S;
  adj.resize(n);
  for(ll i = 0; i < n-1; i++) {
    ll u, v, c , w;
    cin >> u >> v >> c >> w;
    u--, v--;
    adj[u].push_back({v, {c, w}});
    adj[v].push_back({u, {c, w}});
  }
  dfs(0, -1);
  // cout << endl;
  // sort(e.begin(), e.end());
  ll sum = 0;
  vector<ll> A, B;
 for(auto& [w, f, c]: e) {
      if(c == 1) {
          p.push({w, f});
          x += w * f;
      } else {
          q.push({w, f});
          y += w * f;
      }
  }
  vector<int> alpha, beta;
  while(x) {
      alpha.push_back(x);
      auto edge = p.top(); p.pop();
      x -= get(edge);
      p.push(edge);
  }
  while(y) {
      beta.push_back(y);
      auto edge = q.top(); q.pop();
      y -= get(edge);
      q.push(edge);
  }
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
1
5 50
1 3 100 1
1 5 10 2
2 3 123 2
5 4 55 1

3
3 20
2 1 8
3 1 7
5 50
1 3 10
1 5 10
2 3 123
5 4 55
2 100
1 2 409

*/

