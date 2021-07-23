
#include<bits/stdc++.h>

using namespace std;
const int inf = 2e9;

using ll = long long;
ll MOD = 1e9 + 7;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
#define deb(x) cout << #x << " = " << x << endl;


ll mpow2(ll x, ll n) {
  ll ans = 1;
  while (n != 0) {
    if (n & 1) ans = ans * x % MOD;
    x = 1LL * x * x % MOD;
    n >>= 1;
  }
  return ans;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<array<int, 2>>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    adj[v].push_back({u, w});
    adj[u].push_back({v, w});
  }
  int s, d;
  cin >> s >> d;
  s--, d--;
  vector<array<int, 2>> path(n);
  for (int i = 0; i < n; i++) {
    path[i][0] = i;
    path[i][1] = -1;
  }
  long long mini = 0;
  minpq<array<int, 2>> pq;
  vector<int> dis(n, inf);
  pq.push({0, s});
  dis[s] = 0;
  while (!pq.empty()) {
    auto [w, u] = pq.top();
    pq.pop();
    if (w > dis[u]) continue;
    for (auto i : adj[u]) {
      int c = i[1];
      int v = i[0];
      int x = dis[u] + c;
      if (dis[v] > (int)x) {
        dis[v] = (int)x;
        pq.push({dis[v], v});
        path[v][0] = u;
        path[v][1] = c;
      }
    }
  }
//  for (int i = 0; i < n; i++) {
//    cout << path[i][0] << ' ' << path[i][1] << '\n';
//  }
  if (dis[d] == inf) {
    cout << -1 << '\n';
  } else {
    vector<int> res;
    while (true) {
      if (path[d][1] == 0) {
        mini = (mini + 1) % MOD;
      } else if (path[d][1] != -1) {
        mini = (mini + mpow2(2, path[d][1])) % MOD;
      }
      if (path[d][0] == d) break;
      res.push_back(d);
      d = path[d][0];
    }
    res.push_back(d);
    cout << mini << '\n' << (int)res.size() << '\n';
    reverse(res.begin(), res.end());
    for (int i = 0; i < (int)res.size(); i++) {
      cout << res[i] + 1 << ' ';
    } cout << '\n';
  }
  return 0;
} //Hajimemashite

