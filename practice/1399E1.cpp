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
  ll c, f;
};

bool operator<(const Edge& p, const Edge& o) {
  return p.f* ceil((dd)p.c/2.0) < ceil((dd)o.c/2.0)*o.f;
}

vector<Edge>e;

ll n, S;
vector<vector<pair<ll, ll>>>adj;

ll dfs(ll s, ll p) {
  ll fre = 0;
  bool flag = true;
  for(auto i : adj[s]) if(i.first != p){
    ll c = dfs(i.first, s);
    e.push_back({i.second, c});
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
    ll u, v, c;
    cin >> u >> v >> c;
    u--, v--;
    adj[u].push_back({v, c});
    adj[v].push_back({u, c});
  }
  dfs(0, -1);
  // cout << endl;
  // sort(e.begin(), e.end());
  priority_queue<Edge>q;
  ll sum = 0;
  for(auto i : e) {
    // cout << i.u << ' ' << i.v << ' ' << i.c << endl;
    q.push(i);
    sum += (i.f*i.c);
  }
  ll count = 0;
  while(!q.empty()) {
    if(sum <= S) break;
    auto i = q.top();
    q.pop();
    ll nnn = i.c*i.f, nn = i.c/2;
    q.push({nn, i.f});
    sum -= nnn;
    sum += nn*i.f;
    // deb(sum);
    count++;
  }
  cout << count << endl;
  e.clear();
  for(ll i = 0; i < n; i++)
    adj.clear();
  while(!q.empty())
    q.pop();

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
1 3 100
1 5 10
2 3 123
5 4 55

3
3 20
2 1 8
3 1 7
5 50
1 3 100
1 5 10
2 3 123
5 4 55
2 100
1 2 409

*/