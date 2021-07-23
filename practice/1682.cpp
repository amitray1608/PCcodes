#include<bits/stdc++.h>
 
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<vector<int>> rev;
vector<int> order, comp, vis;
 
void dfs1(int s) {
  vis[s] = true;
  for (int u : adj[s]) {
    if (!vis[u]) dfs1(u);
  }
  order.push_back(s);
}
 
void dfs2(int s) {
  vis[s] = true;
  comp.push_back(s);
  for (int u : rev[s]) {
    if (!vis[u]) dfs2(u);
  }
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  cin >> n >> m;
  adj.resize(n);
  rev.resize(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    rev[v].push_back(u);
  }
  vis.resize(n, 0);
  for (int i = 0; i < n; i++) 
    if (!vis[i]) dfs1(i);
  reverse(order.begin(), order.end());
//  for (int i : order) {
//    cout << i << ' ';
//  } cout << '\n';
  vis.assign(n, 0);
  for (int i = 0; i < n; i++) {
    dfs2(order[i]);
    break;
  }
//  for (int i : comp) {
//    cout << i << ' ';
//  } cout << '\n';
  if (comp.size() == n) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
    vector<int>cnt(n, 0);
    for (int i : comp)
      cnt[i]++;
    int ans;
    for(int i = 0; i < n; i++) {
      if (cnt[i] == 0) { 
        ans = i;
        break;
      }
    }
    cout << ans + 1 << ' ' << comp.back() + 1 << '\n';
  }
  return 0;
} //Hajimemashite
 
