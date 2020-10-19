//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

const dd INF = 10000000000000.0;

typedef pair<int, int> P;
int n, m, s, d;
vector<vector<pair<int, dd>>>adj;
vector<dd>dis;

void solve(){
  cin >> n >> m >> s >> d;
  adj.resize(n);
  dis.resize(n, INF);
  for(int i = 0; i < m; i++) {
    int u, v;
    dd x, y;
    cin >> u >> v >> x >> y;
    u--, v--;
    dd time = x/y;
    adj[u].push_back({v, time});
    adj[v].push_back({u, time});
  }
  s--, d--;
  priority_queue<pair<dd, int>, vector<pair<dd, int>>, greater<pair<dd, int>>>q;
  q.push({0.0, s});
  dis[s] = 0.0;
  while(!q.empty()) {
    auto x = q.top();
    q.pop();
    int u = x.second;
    if((dd)dis[u] == (dd)INF) continue;
    for(auto i : adj[u]) {
      int v = i.first;
      dd cost = i.second;
      if(dis[v] > dis[u]+cost) {
        dis[v] = dis[u]+cost;
        q.push({dis[v], v});
      }
    }
  }
  if(dis[d] >= INF)
    cout << -1 << endl;
  else
    cout << dis[d] << endl;

  dis.clear();
  for(int i= 0; i < n; i++)
    adj[i].clear();
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  cout << fixed << setprecision(10) << endl;
  while(t--){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  