
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

const int MOD = 1e9 + 7;
int n, m;
vector<int> val;
vector<vector<int>> adj, rev;
vector<int> order, comp, vis;

void topo(int s) {
  vis[s] = true;
  for (int i : adj[s]) {
    if (!vis[i]) topo(i);
  }
  order.push_back(s);
}

void dfs(int s) {
  vis[s] = true;
  comp.push_back(s);
  for (int i : rev[s]) {
    if (!vis[i]) dfs(i);
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  cin >> n;	
  adj.resize(n);
  rev.resize(n);
  vis.resize(n, false);
  val.resize(n);
  for (int &i : val) cin >> i;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    rev[v].push_back(u);
  }
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) topo(i); 
  }
  reverse(order.begin(), order.end());
  vis.assign(n, false);
  int cost = 0;
  vector<int> mincount;
  for (int i : order) {
    if (!vis[i]) {
      dfs(i);
      map<int, int> mp;
      for (int j : comp) {
        mp[val[j]]++;
      }
      for (auto j : mp) {
        cost += j.first;
        mincount.push_back(j.second);
        break;
      }
      comp.clear();
    }
  }
  int comb = 1;
  for (int i : mincount) {
    comb = (comb * i) % MOD;
  }
  cout << cost << ' ' << comb << '\n';
  return 0;
} //Hajimemashite

