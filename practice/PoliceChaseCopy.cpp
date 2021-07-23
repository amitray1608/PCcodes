
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, m;
vector<vector<ll>> adj;
vector<vector<ll>> oadj;
vector<ll> flow, par;
vector<bool> vis;
const ll inf = 1e10;
ll s, t;

bool check() {
  vis.assign(n, false);
  queue<ll> q;
  q.push(s);
  vis[s] = true;
  while (!q.empty()) {
    ll u = q.front();
    q.pop();
    for (int v = 1; v <= n; v++) {
      if (adj[u][v] and !vis[v]) {
        vis[v] = true;
        par[v] = u;
        q.push(v);
      }
    }
  }
  return vis[t];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  cin >> n >> m;
  adj.resize(n + 1, vector<ll>(n + 1, 0));
  oadj.resize(n + 1, vector<ll>(n + 1, 0));
  vis.resize(n + 1, false);
  par.resize(n + 1, 0);
  flow.resize(n + 1, inf);
  for (ll i = 0; i < m; i++) {
    ll u, v;
    cin >> u >> v;
    adj[u][v]++;
    //adj[v][u]++;
    oadj[u][v]++;
    //oadj[v][u]++;
  }
  ll u, v;
  cin >> s >> t;
  while (check()) {
    ll floww = inf;
    for (v = t; v != s; v = par[v]) {
      u = par[v];
      floww = min(floww, adj[u][v]);
    }
    for (v = t; v != s; v = par[v]) {
      u = par[v];
      adj[u][v] -= floww;
      adj[v][u] += floww;
    }
  }
  check();
  vector<pair<int, int>> ans;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (vis[i] and !vis[j] and oadj[i][j]) {
        ans.push_back({i, j});
      }

  vector<int> count(n + 1, 0);
  vector<set<int>> st(n + 1);
  cout << ans.size() << '\n';
  for (auto i : ans) {
    st[i.first].insert(i.second);
    st[i.second].insert(i.first);
    count[i.first]++;
    count[i.second]++;
    cout << i.first <<  ' ' << i.second << '\n';
  }
  vector<int> nodes;
  while (true) {
    int maxi = 0, nd = 0;
    for (int i = 1; i <= n; i++) {
      if (maxi < count[i]) {
        maxi = count[i];
        nd = i;
      }
    }
    if (nd) {
      nodes.push_back(nd);
      count[nd] = 0;
      for (auto i : st[nd]) {
        st[i].erase(nd);
        count[i]--;
      }
      st[nd].clear();
    } else break;
  }
  for (int i : nodes) {
    cout << i << ' ';
  }
  cout << '\n';
  return 0;
} //Hajimemashite

